#include <String.h>
#include <math.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define PI 3.14159
bool flag = true;
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
String command;

// array of max and min pwm values for servos, found from servo_calibration.ino
const int SERVO_MIN[16] = {70, 70, 100, 0, 70, 70, 100, 0, 70, 70, 100, 0, 70, 70, 100, 0};
const int SERVO_MAX[16] = {450, 450, 470, 0, 450, 450, 470, 0, 450, 450, 470, 0, 450, 450, 470, 0};


/////////////////////////// ADJUSTABLE PARAMETERS ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FLIP DIRECTIONS IF NECESSARY  ///////////////////////////////

const int SERVO_DIR[16] = {1, -1, 1, 0, -1, 1, 1, 0, 1, -1, 1, 0, -1, 1, 1, 0};  // flip direction of servo 

/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////  ADJUST IF NEEDED (for front right leg)  ////////////////////////////////////////////

const int THETA1_INIT = 45; // initial joint angles (degree)
const int THETA3_INIT = 0;
const int THETA2_INIT = 90;

const int THETA1_LEFT_ANGLE = 90;  // shoulder servo (servo 0) front and back angles
const int THETA1_RIGHT_ANGLE = 30;

const int THETA2_PRESSURE_ANGLE = 90;  // elbow servo (servo 1) pressure and release angles
const int THETA2_RELEASE_ANGLE = 50;

const int THETA3_PULL_ANGLE = 0;  // gripper servo (servo 2) pull and release angle
const int THETA3_RELEASE_ANGLE = 140;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for front left leg)  ////////////////////////////////////////////

const int THETA4_INIT = 45; // initial joint angles (degree)
const int THETA6_INIT = 0;
const int THETA5_INIT = 90;

const int THETA4_RIGHT_ANGLE = 90;  // shoulder servo (servo 0) front and back angles
const int THETA4_LEFT_ANGLE = 30;

const int THETA5_PRESSURE_ANGLE = 90;  // elbow servo (servo 1) pressure and release angles
const int THETA5_RELEASE_ANGLE = 50;

const int THETA6_PULL_ANGLE = 140;  // gripper servo (servo 2) pull and release angle
const int THETA6_RELEASE_ANGLE = 0;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for back right leg)  ////////////////////////////////////////////

const int THETA7_INIT = 45; // initial joint angles (degree)
const int THETA9_INIT = 0;
const int THETA8_INIT = 90;

const int THETA7_LEFT_ANGLE = 90;  // shoulder servo (servo 0) front and back angles
const int THETA7_RIGHT_ANGLE = 30;

const int THETA8_PRESSURE_ANGLE = 90;  // elbow servo (servo 1) pressure and release angles
const int THETA8_RELEASE_ANGLE = 50;

const int THETA9_PULL_ANGLE = 0;  // gripper servo (servo 2) pull and release angle
const int THETA9_RELEASE_ANGLE = 140;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for back left leg)  ////////////////////////////////////////////

const int THETA10_INIT = 45; // initial joint angles (degree)
const int THETA12_INIT = 0;
const int THETA11_INIT = 90;

const int THETA10_RIGHT_ANGLE = 90;  // shoulder servo (servo 0) front and back angles
const int THETA10_LEFT_ANGLE = 30;

const int THETA11_PRESSURE_ANGLE = 90;  // elbow servo (servo 1) pressure and release angles
const int THETA11_RELEASE_ANGLE = 50;

const int THETA12_PULL_ANGLE = 140;  // gripper servo (servo 2) pull and release angle
const int THETA12_RELEASE_ANGLE = 0;

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
  for(int i=0; i<=3; i++){
    int PWM = angle_to_pwm(theta[i], servo_idx[i]);
    pwm.setPWM(servo_idx[i], 0, PWM);

    Serial.println("Servo " + String(servo_idx[i]) + " to position " + String(theta[i]) + "; PWM: " + String(PWM));
    Serial.println(" ");
  }
  Serial.println(" ");
}

// function for executing a trajectory once
void front_right_back_left_forward(){

  int servo_idx_front[4] = {4, 0, 1, 2};
  int servo_idx_back[4] = {12, 8, 13, 14};

  Serial.println("Executing front-right forward, back-left forward movement:");
  Serial.println("");

  ////////// adjust theta /////////////
  float theta1f[4] = {THETA4_LEFT_ANGLE, THETA1_LEFT_ANGLE, THETA2_PRESSURE_ANGLE, THETA3_PULL_ANGLE};
  float theta2f[4] = {THETA4_LEFT_ANGLE, THETA1_LEFT_ANGLE, THETA2_RELEASE_ANGLE, THETA3_PULL_ANGLE};
  float theta3f[4] = {THETA4_RIGHT_ANGLE, THETA1_RIGHT_ANGLE, THETA2_RELEASE_ANGLE, THETA3_RELEASE_ANGLE};
  float theta4f[4] = {THETA4_RIGHT_ANGLE, THETA1_RIGHT_ANGLE, THETA2_PRESSURE_ANGLE, THETA3_RELEASE_ANGLE};

  float theta1b[4] = {THETA10_RIGHT_ANGLE, THETA7_RIGHT_ANGLE, THETA11_PRESSURE_ANGLE, THETA12_PULL_ANGLE};
  float theta2b[4] = {THETA10_RIGHT_ANGLE, THETA7_RIGHT_ANGLE, THETA11_RELEASE_ANGLE, THETA12_PULL_ANGLE};
  float theta3b[4] = {THETA10_LEFT_ANGLE, THETA7_LEFT_ANGLE, THETA11_RELEASE_ANGLE, THETA12_RELEASE_ANGLE};
  float theta4b[4] = {THETA10_LEFT_ANGLE, THETA7_LEFT_ANGLE, THETA11_PRESSURE_ANGLE, THETA12_RELEASE_ANGLE};
  /////////////////////////////////////

  move_servos(servo_idx_front, theta1f);
  move_servos(servo_idx_back, theta1b);
  delay(500);
  move_servos(servo_idx_front, theta2f);
  move_servos(servo_idx_back, theta2b);
  delay(500);
  move_servos(servo_idx_front, theta3f);
  move_servos(servo_idx_back, theta3b);
  delay(500);
  move_servos(servo_idx_front, theta4f);
  move_servos(servo_idx_back, theta4b);
}


// function for executing a trajectory once
void front_left_back_right_forward(){

  int servo_idx_front[4] = {4, 0, 5, 6};
  int servo_idx_back[4] = {12, 8, 9, 10};

  Serial.println("Executing front-left forward, back_right forward movement:");
  Serial.println("");

  ////////// adjust theta /////////////
  float theta1f[4] = {THETA4_RIGHT_ANGLE, THETA1_RIGHT_ANGLE, THETA5_PRESSURE_ANGLE, THETA6_PULL_ANGLE};
  float theta2f[4] = {THETA4_RIGHT_ANGLE, THETA1_RIGHT_ANGLE, THETA5_RELEASE_ANGLE, THETA6_PULL_ANGLE};
  float theta3f[4] = {THETA4_LEFT_ANGLE, THETA1_LEFT_ANGLE, THETA5_RELEASE_ANGLE, THETA6_RELEASE_ANGLE};
  float theta4f[4] = {THETA4_LEFT_ANGLE, THETA1_LEFT_ANGLE, THETA5_PRESSURE_ANGLE, THETA6_RELEASE_ANGLE};

  float theta1b[4] = {THETA10_LEFT_ANGLE, THETA7_LEFT_ANGLE, THETA8_PRESSURE_ANGLE, THETA9_PULL_ANGLE};
  float theta2b[4] = {THETA10_LEFT_ANGLE, THETA7_LEFT_ANGLE, THETA8_RELEASE_ANGLE, THETA9_PULL_ANGLE};
  float theta3b[4] = {THETA10_RIGHT_ANGLE, THETA7_RIGHT_ANGLE, THETA8_RELEASE_ANGLE, THETA9_RELEASE_ANGLE};
  float theta4b[4] = {THETA10_RIGHT_ANGLE, THETA7_RIGHT_ANGLE, THETA8_PRESSURE_ANGLE, THETA9_RELEASE_ANGLE};
  /////////////////////////////////////

  move_servos(servo_idx_front, theta1f);
  move_servos(servo_idx_back, theta1b);
  delay(500);
  move_servos(servo_idx_front, theta2f);
  move_servos(servo_idx_back, theta2b);
  delay(500);
  move_servos(servo_idx_front, theta3f);
  move_servos(servo_idx_back, theta3b);
  delay(500);
  move_servos(servo_idx_front, theta4f);
  move_servos(servo_idx_back, theta4b);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("Friendly-neighbour Rocko"); //Bluetooth device name
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(1000);

  // set an initial position
  Serial.println("Setting initial servo positions: front-right forward, back-left forward");
  
  front_left_back_right_forward(); // perform initial movement
  
  delay(2000);
}

void loop() {

  if(SerialBT.available()>0){
    
    command = SerialBT.readString();
    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(flag){
      front_right_back_left_forward();  // execute the desired trajectory
      SerialBT.println("front right back left");
    }
    else{
      front_left_back_right_forward();  // execute the desired trajectory
      SerialBT.println("front left back right");
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    delay(20);
  } 
}
