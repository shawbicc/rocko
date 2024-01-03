#include <math.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define PI 3.14159

// array of max and min pwm values for servos
const int SERVO_MIN[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 70, 0};
const int SERVO_MAX[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 470, 450, 450};

// link lengths (mm)
const float LEN1 = 107.0;
const float LEN2 = 90.0;

// initial joint angles (degree)
const int THETA1_INIT = 90;
const int THETA3_INIT = 0;
const int THETA2_INIT = 180;


// function to convert angle (rad) to pwm
int angle_to_pwm(int angle, int servo_idx){
  return map(angle, -90, 90, SERVO_MIN[servo_idx], SERVO_MAX[servo_idx]);
}

// function to convert pwm to angle (rad)
int pwm_to_angle(int pwm_val, int servo_idx){
  return map(pwm_val, SERVO_MIN[servo_idx], SERVO_MAX[servo_idx], -90, 90);
}

// function to convert degree to radian
float radian(float degree) {return degree*PI/180;}

// function to convert radian to degree
float degree(float radian) {return radian*180/PI;}

// function for converting (x,y) into (theta1,theta2)
void inverse_kinematics(float* angle_array, float x, float y, float l1, float l2){
  float theta1 = acos(((x*x) + (y*y) - (l1*l1) - (l2*l2)) / (2*l1*l2));
  float theta3 = atan(y/x) - atan((l2*sin(theta2)) / (l1 + l2*cos(theta2)));
  float theta2 = PI;

  angle_array[0] = theta1 - radian(THETA1_INIT);
  angle_array[1] = theta2 - radian(THETA2_INIT);
  angle_array[2] = theta3 - radian(THETA3_INIT);
}

// function for generating trajectory

// fucntion for moving the servos to given position (degree)
void move_servos(float* theta, int* servo_idx){
  for(int i=0; i<sizeof(theta); i++){
    int PWM = angle_to_pwm(theta[i], servo_idx[i]);
    pwm.setPWM(servo_idx[i], 0, PWM);

    Serial.print("Servo ");
    Serial.print(servo_idx[i]);
    Serial.print(" to position ");
    Serial.print(degree(theta[i]));
    Serial.println(" ");
  }
}


// function for executing a trajectory once
void execute_path(float* theta){
  inverse_kinematics(theta, 0, 107+90, LEN1, LEN2);

  Serial.println("Executing path: ");
  Serial.println(degree(theta[0]));
  Serial.println(degree(theta[1]));
  Serial.println(degree(theta[2]));
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
  // set all angles to 0
  Serial.println("Setting initial servo positions: ");
  float initial_angles[3] = {0.0, 0.0, 0.0};
  int servo_idx[3] = {13, 14, 15};
  move_servos(initial_angles, servo_idx);
  
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float theta[2];
  execute_path(theta);
  delay(3000);
}
