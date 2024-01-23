#include <math.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define PI 3.14159

// array of max and min pwm values for servos
const int SERVO_MIN[16] = {70, 70, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int SERVO_MAX[16] = {450, 450, 470, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// array for servo direction
/////////////////////////////// FLIP DIRECTIONS IF NECESSARY  ///////////////////////////////

const int SERVO_DIR[16] = {-1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

/////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// SET ARM LENGTHS (mm)  //////////////////////////////////

const float LEN1 = 107.0;
const float LEN2 = 90.0;

/////////////////////////////////////////////////////////////////////////////////////////////

// initial joint angles (degree)
/////////////////////////////  ADJUST IF NEEDED  ////////////////////////////////////////////

const int THETA1_INIT = 90;
const int THETA3_INIT = 0;
const int THETA2_INIT = 0;

/////////////////////////////////////////////////////////////////////////////////////////////

// function for generating x trajectory
///////////////////////////  SET PARAMETRIC EQUATION FOR DESIRED X TRAJECTORY  //////////////

float generate_x_trajectory(float u){
  return 5.0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// function for generating y trajectory

///////////////////////////  SET PARAMETRIC EQUATION FOR DESIRED X TRAJECTORY  //////////////

float generate_y_trajectory(float u){
  return 130 - 50*sin(((u)/10)*2*PI);
}

/////////////////////////////////////////////////////////////////////////////////////////////



// NECESSARY FUNCTIONS, NO NEED TO ADJUST

// function to convert angle (deg) to pwm; maps min-max to 0-180 by default
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


// function for converting (x,y) into (theta1,theta2); takes an array of 3 float numbers and populates them with angle values
// NOTE: for now, motion is limited to xy plane
void inverse_kinematics(float* angle_array, float x, float y){
  float theta3 = acos(((x*x) + (y*y) - (LEN1*LEN1) - (LEN2*LEN2)) / (2*LEN1*LEN2));
  float theta1 = atan(y/x) - atan((LEN2*sin(theta3)) / (LEN1 + LEN2*cos(theta3)));
  float theta2 = 0.0;

  angle_array[0] = degree(theta1) ;
  angle_array[1] = degree(theta2) ;
  angle_array[2] = degree(theta3) ;
}


// fucntion for moving the servos to given position (degree)
void move_servos(int* servo_idx, float* theta){
  for(int i=0; i<=sizeof(theta); i++){
    int PWM = angle_to_pwm(theta[i], servo_idx[i]);
    // pwm.setPWM(servo_idx[i], 0, PWM);

    Serial.print("Servo ");
    Serial.print(servo_idx[i]);
    Serial.print(" to position ");
    Serial.print(theta[i]);
    Serial.print("; PWM: ");
    Serial.print(PWM);
    Serial.println(" ");
  }
  Serial.println(" ");
}


// function for executing a trajectory once
void execute_path(int* servo_idx, float* theta){

  for(float u = 0.0; u<=10.0; u+=0.01){
    // array for servo angles
    float theta[3];

    // generate desired x,y coordinates of gripper
    float x = generate_x_trajectory(u);
    float y = generate_y_trajectory(u);
    
    // calculate angles for reaching that point
    inverse_kinematics(theta, x, y);

    // apply angles to servo 
    move_servos(servo_idx, theta);

    // print the angles in serial monitor
    Serial.println("Executing Angles: ");
    Serial.println((theta[0]));
    Serial.println((theta[1]));
    Serial.println((theta[2]));
    delay(500);
  }
}


void setup() {
  // initiate serial monitor and PWM driver
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(1000);

  // set an initial position
  Serial.println("Setting initial servo positions: ");
  float initial_angles[3] = {(THETA1_INIT), (THETA2_INIT), (THETA3_INIT)};
  int servo_idx[3] = {0, 1, 2};
  move_servos(servo_idx, initial_angles);
  
  delay(2000);
}

void loop() {

  float theta[3];  // array for angles
  int servo_idx[3] = {0, 1, 2};  // array for servo index according to wiring on Servo driver 

  execute_path(servo_idx, theta);  // execute the desired trajectory
  delay(3000);

}
