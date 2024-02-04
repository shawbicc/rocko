
#include <math.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define PI 3.14159
bool flag = true;

// array of max and min pwm values for servos, found from servo_calibration.ino
const int SERVO_MIN[16] = {70, 70, 100, 70, 70, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int SERVO_MAX[16] = {450, 450, 470, 450, 450, 470, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


/////////////////////////// ADJUSTABLE PARAMETERS ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FLIP DIRECTIONS IF NECESSARY  ///////////////////////////////

const int SERVO_DIR[16] = {1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // flip direction of servo 

/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////  ADJUST IF NEEDED (for front right leg)  ////////////////////////////////////////////

const int THETA1_INIT = 45; // initial joint angles (degree)
const int THETA3_INIT = 0;
const int THETA2_INIT = 90;

const int THETA1_FRONT_ANGLE = 30;  // shoulder servo (servo 0) front and back angles
const int THETA1_BACK_ANGLE = 90;

const int THETA2_PRESSURE_ANGLE = 90;  // elbow servo (servo 1) pressure and release angles
const int THETA2_RELEASE_ANGLE = 50;

const int THETA3_PULL_ANGLE = 180;  // gripper servo (servo 2) pull and release angle
const int THETA3_RELEASE_ANGLE = 0;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for front left leg)  ////////////////////////////////////////////

const int THETA4_INIT = 45; // initial joint angles (degree)
const int THETA6_INIT = 0;
const int THETA5_INIT = 60;

const int THETA4_FRONT_ANGLE = 30;  // shoulder servo (servo 0) front and back angles
const int THETA4_BACK_ANGLE = 90;

const int THETA5_PRESSURE_ANGLE = 90;  // elbow servo (servo 1) pressure and release angles
const int THETA5_RELEASE_ANGLE = 50;

const int THETA6_PULL_ANGLE = 180;  // gripper servo (servo 2) pull and release angle
const int THETA6_RELEASE_ANGLE = 0;

/////////////////////////////////////////////////////////////////////////////////////////////
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

// fucntion for moving the servos to given position (degree)
void move_servos(int* servo_idx, float* theta){
  for(int i=0; i<=sizeof(theta); i++){
    int PWM = angle_to_pwm(theta[i], servo_idx[i]);
    pwm.setPWM(servo_idx[i], 0, PWM);

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
void right_leg_forward(){

  int servo_idx[3] = {0, 1, 2};

  Serial.println("Executing right leg forward movement:");
  Serial.println("");
  ////////// adjust theta /////////////
  float theta1[3] = {THETA1_FRONT_ANGLE, THETA2_RELEASE_ANGLE, 0};
  float theta2[3] = {THETA1_FRONT_ANGLE, THETA2_PRESSURE_ANGLE, 0};
  /////////////////////////////////////
  
  move_servos(servo_idx, theta1);
  delay(200);
  move_servos(servo_idx, theta2);
  //delay(2000);
}

// function for executing a backward trajectory once
void right_leg_backward(){

  const int servo_idx[3] = {0, 1, 2};

  Serial.println("Executing right leg backward movement:");
  Serial.println("");
  ///////// adjust theta ////////////////
  float theta1[3] = {THETA1_BACK_ANGLE, THETA2_PRESSURE_ANGLE, 0};
  float theta2[3] = {THETA1_BACK_ANGLE, THETA2_RELEASE_ANGLE, 0};
  ///////////////////////////////////////
  move_servos(servo_idx, theta1);
  delay(200);
  move_servos(servo_idx, theta2);
  //delay(2000);
}

// function for executing a trajectory once
void left_leg_forward(){

  int servo_idx[3] = {3, 4, 5};

  Serial.println("Executing left leg forward movement:");
  Serial.println("");
  ////////// adjust theta /////////////
  float theta1[3] = {THETA4_FRONT_ANGLE, THETA5_RELEASE_ANGLE, 0};
  float theta2[3] = {THETA4_FRONT_ANGLE, THETA5_PRESSURE_ANGLE, 0};
  /////////////////////////////////////
  
  move_servos(servo_idx, theta1);
  delay(200);
  move_servos(servo_idx, theta2);
  //delay(2000);
}

// function for executing a backward trajectory once
void left_leg_backward(){

  const int servo_idx[3] = {3, 4, 5};

  Serial.println("Executing left leg backward movement:");
  Serial.println("");
  ///////// adjust theta ////////////////
  float theta1[3] = {THETA4_BACK_ANGLE, THETA5_PRESSURE_ANGLE, 0};
  float theta2[3] = {THETA4_BACK_ANGLE, THETA5_RELEASE_ANGLE, 0};
  ///////////////////////////////////////
  move_servos(servo_idx, theta1);
  delay(200);
  move_servos(servo_idx, theta2);
  //delay(2000);
}


void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){

    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(flag){
      right_leg_forward();  // execute the desired trajectory
      left_leg_backward();
      delay(3000);
    }
    else{
      right_leg_backward();
      left_leg_forward();  // execute the desired trajectory
      delay(3000);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    while(Serial.available()>0){
      String garbage = Serial.readString();
    }
  }
}
