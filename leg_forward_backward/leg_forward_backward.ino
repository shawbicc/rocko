#include <math.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define PI 3.14159

// array of max and min pwm values for servos
const int SERVO_MIN[16] = {70, 70, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int SERVO_MAX[16] = {450, 450, 470, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// array of servo direction
const int SERVO_DIR[16] = {-1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// link lengths (mm)
const float LEN1 = 107.0;
const float LEN2 = 90.0;

// initial joint angles (degree)
const int THETA1_INIT = 90;
const int THETA3_INIT = 0;
const int THETA2_INIT = 0;


// function to convert angle (deg) to pwm
// maps min-max to 0-180 by default
int angle_to_pwm(int angle, int servo_idx){
  if(SERVO_DIR[servo_idx] == 1){ return map(angle, 0, 180, SERVO_MIN[servo_idx], SERVO_MAX[servo_idx]);}
  else if(SERVO_DIR[servo_idx] == -1) {return map(angle, 0, 180, SERVO_MAX[servo_idx], SERVO_MIN[servo_idx]);}
  else{ 
    Serial.println("Invalid rotation direction!");
    return ((SERVO_MAX[servo_idx]+SERVO_MIN[servo_idx])/2); // return average if invalid direction  
  };
}

// function to convert pwm to angle (deg)
int pwm_to_angle(int pwm_val, int servo_idx){
  if(SERVO_DIR[servo_idx] == 1){ return map(pwm_val, SERVO_MIN[servo_idx], SERVO_MAX[servo_idx], 0, 180); }
  else if(SERVO_DIR[servo_idx] == -1){ return map(pwm_val, SERVO_MAX[servo_idx], SERVO_MIN[servo_idx], 0, 180); }
  else{ 
    Serial.println("Invalid rotation direction!");
    return 0; // return average if invalid direction  
  };
}

// function to convert degree to radian
float radian(float degree) {return degree*PI/180;}

// function to convert radian to degree
float degree(float radian) {return radian*180/PI;}

// function for converting (x,y) into (theta1,theta2)

// NEED SOME ANGLE FIX
void inverse_kinematics(float* angle_array, float x, float y){
  float theta1 = acos(((x*x) + (y*y) - (LEN1*LEN1) - (LEN2*LEN2)) / (2*LEN1*LEN2));
  float theta3 = atan(y/x) - atan((LEN2*sin(theta1)) / (LEN1 + LEN2*cos(theta1)));
  float theta2 = PI;

  // angle_array[0] = theta1 - radian(THETA1_INIT);
  // angle_array[1] = theta2 - radian(THETA2_INIT);
  // angle_array[2] = theta3 - radian(THETA3_INIT);

  angle_array[0] = degree(theta1) ;
  angle_array[1] = degree(theta2) ;
  angle_array[2] = degree(theta3) ;
}

// function for generating trajectory
float* generate_x_trajectory(float* u){
  float x[50];
  for(int i=0; i<sizeof(u); i++){
    // parametric equation for x
    x[i] = 0;
  }
  return x;
}

float* generate_y_trajectory(float* u){
  float y[50];
  for(int i=0; i<sizeof(u); i++){
    // parametric equation for y
    y[i] = 50 + 30*sin(u[i]);
  }
  return y;
}

// fucntion for moving the servos to given position (degree)
void move_servos(float* theta, int* servo_idx){
  for(int i=0; i<=sizeof(theta); i++){
    int PWM = angle_to_pwm(theta[i], servo_idx[i]);
    pwm.setPWM(servo_idx[i], 0, PWM);
    Serial.println(PWM);

    Serial.print("Servo ");
    Serial.print(servo_idx[i]);
    Serial.print(" to position ");
    Serial.print(theta[i]);
    Serial.println(" ");
  }
  Serial.println(" ");
}


// function for executing a trajectory once
void execute_path(float* theta){

  int servo_idx[3] = {0, 1, 2};

  for(int u = 0; u<=360; u+=10){

    float x = 0; // parametric eqn for x
    // float y = 50 + 30*sin(radian(u)); // parametric eqn for y
    float y = LEN1+LEN2;
    
    inverse_kinematics(theta, x, y);

    move_servos(theta, servo_idx);

    Serial.println("Executing path: ");
    Serial.println((theta[0]));
    Serial.println((theta[1]));
    Serial.println((theta[2]));
    delay(500);
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(1000);

  // set all angles to 0
  Serial.println("Setting initial servo positions: ");
  float initial_angles[3] = {(THETA1_INIT), (THETA2_INIT), (THETA3_INIT)};
  int servo_idx[3] = {0, 1, 2};
  move_servos(initial_angles, servo_idx);
  
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float theta[3];
  execute_path(theta);
  delay(3000);

  // float theta[3] = {0, 0, 0};
  // int servo_idx[3] = {0, 1, 2};
  // move_servos(theta, servo_idx);
  // delay(5000);

}
