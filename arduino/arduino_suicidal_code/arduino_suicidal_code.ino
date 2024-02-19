#include <String.h>
#include <math.h>
#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define SERVO1_PIN A5
#define SERVO2_PIN A4
#define SERVO3_PIN A3
#define SERVO4_PIN A2
#define SERVO5_PIN A1
#define SERVO6_PIN A0
#define SERVO7_PIN 11
#define SERVO8_PIN 10
#define SERVO9_PIN 9
#define SERVO10_PIN 6
#define SERVO11_PIN 5
#define SERVO12_PIN 3

Servo SERVO1;
Servo SERVO2;
Servo SERVO3;
Servo SERVO4;
Servo SERVO5;
Servo SERVO6;
Servo SERVO7;
Servo SERVO8;
Servo SERVO9;
Servo SERVO10;
Servo SERVO11;
Servo SERVO12;

#define PI 3.14159
bool flag = true;
SoftwareSerial BTserial(0, 1);

char command;


/////////////////////////// ADJUSTABLE PARAMETERS ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FLIP DIRECTIONS IF NECESSARY  ///////////////////////////////

const int SERVO_DIR[16] = {1, -1, 1, 0, -1, 1, 1, 0, 1, -1, 1, 0, -1, 1, 1, 0};  // flip direction of servo 

/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////  ADJUST IF NEEDED (for front right leg)  ////////////////////////////////////////////

const int THETA1_INIT = 55; // initial joint angles (degree)
const int THETA2_INIT = 30;
const int THETA3_INIT = 90;

const int THETA1_BACK_ANGLE = 0;  // shoulder servo (servo 0) front and back angles
const int THETA1_FRONT_ANGLE = 110;

const int THETA2_PRESSURE_ANGLE = 15;  // elbow servo (servo 1) pressure and release angles
const int THETA2_RELEASE_ANGLE = 60;

const int THETA3_PULL_ANGLE = 0;  // gripper servo (servo 2) pull and release angle
const int THETA3_RELEASE_ANGLE = 90;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for front left leg)  ////////////////////////////////////////////

const int THETA4_INIT = 55; // initial joint angles (degree)
const int THETA5_INIT = 30;
const int THETA6_INIT = 90;

const int THETA4_BACK_ANGLE = 110;  // shoulder servo (servo 0) front and back angles
const int THETA4_FRONT_ANGLE = 0;

const int THETA5_PRESSURE_ANGLE = 45;  // elbow servo (servo 1) pressure and release angles
const int THETA5_RELEASE_ANGLE = 0;

const int THETA6_PULL_ANGLE = 0;  // gripper servo (servo 2) pull and release angle
const int THETA6_RELEASE_ANGLE = 90;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for back right leg)  ////////////////////////////////////////////

const int THETA7_INIT = 30; // initial joint angles (degree)
const int THETA8_INIT = 30;
const int THETA9_INIT = 90;

const int THETA7_BACK_ANGLE = 0;  // shoulder servo (servo 0) front and back angles
const int THETA7_FRONT_ANGLE = 60;

const int THETA8_PRESSURE_ANGLE = 10;  // elbow servo (servo 1) pressure and release angles
const int THETA8_RELEASE_ANGLE = 60;

const int THETA9_PULL_ANGLE = 15;  // gripper servo (servo 2) pull and release angle
const int THETA9_RELEASE_ANGLE = 90;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  ADJUST IF NEEDED (for back left leg)  ////////////////////////////////////////////

const int THETA10_INIT = 30; // initial joint angles (degree)
const int THETA11_INIT = 30;
const int THETA12_INIT = 90;

const int THETA10_BACK_ANGLE = 60;  // shoulder servo (servo 0) front and back angles
const int THETA10_FRONT_ANGLE = 0;

const int THETA11_PRESSURE_ANGLE = 45;  // elbow servo (servo 1) pressure and release angles
const int THETA11_RELEASE_ANGLE = 0;

const int THETA12_PULL_ANGLE = 0;  // gripper servo (servo 2) pull and release angle
const int THETA12_RELEASE_ANGLE = 90;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


// NECESSARY FUNCTIONS, NO NEED TO ADJUST

void front_right_back_left_1(){
  SERVO5.write(THETA5_PRESSURE_ANGLE);
  SERVO8.write(THETA8_PRESSURE_ANGLE);
  // GRIPPER RELEASE FRONT
  SERVO4.write(THETA4_FRONT_ANGLE);
  SERVO1.write(THETA1_BACK_ANGLE);
  SERVO2.write(THETA2_PRESSURE_ANGLE);
  SERVO3.write(THETA3_PULL_ANGLE); 
  // GRIPPER RELEASE BACK
  SERVO10.write(THETA10_BACK_ANGLE);
  SERVO7.write(THETA7_FRONT_ANGLE);
  SERVO11.write(THETA11_PRESSURE_ANGLE);
  SERVO12.write(THETA12_PULL_ANGLE);
}

void front_right_back_left_2(){
  SERVO5.write(THETA5_PRESSURE_ANGLE);
  SERVO8.write(THETA8_PRESSURE_ANGLE);
  // ARM UP FRONT
  SERVO4.write(THETA4_FRONT_ANGLE);
  SERVO1.write(THETA1_BACK_ANGLE);
  SERVO2.write(THETA2_RELEASE_ANGLE);
  
  // ARM UP BACK
  SERVO10.write(THETA10_BACK_ANGLE);
  SERVO7.write(THETA7_FRONT_ANGLE);
  SERVO11.write(THETA11_RELEASE_ANGLE);
  delay(1000);
  SERVO2.write(THETA12_RELEASE_ANGLE);
  SERVO3.write(THETA3_RELEASE_ANGLE); 
}

void front_right_back_left_3(){
  SERVO5.write(THETA5_PRESSURE_ANGLE);
  SERVO8.write(THETA8_PRESSURE_ANGLE);
  // FRONT LEG FRONT, GRIPPER RELEASE
  SERVO2.write(THETA2_RELEASE_ANGLE);
  SERVO3.write(THETA3_RELEASE_ANGLE);
  SERVO11.write(THETA11_RELEASE_ANGLE);
  SERVO12.write(THETA12_RELEASE_ANGLE);

  for(int f = THETA1_BACK_ANGLE; f <= THETA1_FRONT_ANGLE; f++){
    SERVO4.write(f);
    SERVO1.write(f);

    SERVO10.write(THETA1_FRONT_ANGLE - f);
    SERVO7.write(THETA1_FRONT_ANGLE - f);
    delay(20);
  } 
}

void front_right_back_left_4(){
  SERVO5.write(THETA5_PRESSURE_ANGLE);
  SERVO8.write(THETA8_PRESSURE_ANGLE);
  // ARM DOWN FRONT 
  SERVO4.write(THETA4_BACK_ANGLE);
  SERVO1.write(THETA1_FRONT_ANGLE);
  SERVO2.write(THETA2_PRESSURE_ANGLE);
  SERVO3.write(THETA3_RELEASE_ANGLE); 
  // ARM DOWN BACK
  SERVO10.write(THETA10_FRONT_ANGLE);
  SERVO7.write(THETA7_BACK_ANGLE);
  SERVO11.write(THETA11_PRESSURE_ANGLE);
  SERVO12.write(THETA12_RELEASE_ANGLE);
}





// function for executing a trajectory once
void front_right_back_left_forward(){

  Serial.println("Executing front-right forward, back-left forward movement:");
  Serial.println("");

  front_right_back_left_1();

  delay(700);

  front_right_back_left_2();

  delay(700);

  front_right_back_left_3();

  delay(700);
  
  front_right_back_left_4();

  delay(700);
}

void front_left_back_right_1(){
  SERVO2.write(THETA2_PRESSURE_ANGLE);
  SERVO11.write(THETA11_PRESSURE_ANGLE);
  // GRIPPER RELEASE FRONT
  SERVO4.write(THETA4_BACK_ANGLE);
  SERVO1.write(THETA1_FRONT_ANGLE);
  SERVO5.write(THETA5_PRESSURE_ANGLE);
  SERVO6.write(THETA6_PULL_ANGLE); 
  // GRIPPER RELEASE BACK
  SERVO10.write(THETA10_FRONT_ANGLE);
  SERVO7.write(THETA7_BACK_ANGLE);
  SERVO8.write(THETA8_PRESSURE_ANGLE);
  SERVO9.write(THETA9_PULL_ANGLE);
}

void front_left_back_right_2(){
  SERVO2.write(THETA2_PRESSURE_ANGLE);
  SERVO11.write(THETA11_PRESSURE_ANGLE);
  // ARM UP FRONT
  SERVO4.write(THETA4_BACK_ANGLE);
  SERVO1.write(THETA1_FRONT_ANGLE);
  SERVO5.write(THETA5_RELEASE_ANGLE);
  
  // ARM UP BACK
  SERVO10.write(THETA10_FRONT_ANGLE);
  SERVO7.write(THETA7_BACK_ANGLE);
  SERVO8.write(THETA8_RELEASE_ANGLE);
  delay(1000);
  SERVO9.write(THETA9_RELEASE_ANGLE);
  SERVO6.write(THETA6_RELEASE_ANGLE); 
}

void front_left_back_right_3(){
  SERVO2.write(THETA2_PRESSURE_ANGLE);
  SERVO11.write(THETA11_PRESSURE_ANGLE);
  // FRONT LEG FRONT
  SERVO5.write(THETA5_RELEASE_ANGLE);
  SERVO6.write(THETA6_RELEASE_ANGLE);
  SERVO8.write(THETA8_RELEASE_ANGLE);
  SERVO9.write(THETA9_RELEASE_ANGLE); 

  for(int f = THETA1_FRONT_ANGLE; f >= THETA1_BACK_ANGLE; f--){
    SERVO4.write(f);
    SERVO1.write(f);
    
    SERVO10.write(THETA1_FRONT_ANGLE - f);
    SERVO7.write(THETA1_FRONT_ANGLE - f);
    delay(20);
  }
}

void front_left_back_right_4(){
  SERVO2.write(THETA2_PRESSURE_ANGLE);
  SERVO11.write(THETA11_PRESSURE_ANGLE);
  SERVO4.write(THETA4_FRONT_ANGLE);
  SERVO1.write(THETA1_BACK_ANGLE);
  SERVO5.write(THETA5_PRESSURE_ANGLE);
  SERVO6.write(THETA6_RELEASE_ANGLE); 
  // BACK LEG FRONT
  SERVO10.write(THETA10_BACK_ANGLE);
  SERVO7.write(THETA7_FRONT_ANGLE);
  SERVO8.write(THETA8_PRESSURE_ANGLE);
  SERVO9.write(THETA9_RELEASE_ANGLE);
}

// function for executing a trajectory once
void front_left_back_right_forward(){

  Serial.println("Executing front-left forward, back_right forward movement:");
  Serial.println("");
  
  front_left_back_right_1();

  delay(700);
  
  front_left_back_right_2();

  delay(700);

  front_left_back_right_3();

  delay(700);

  front_left_back_right_4();

  delay(700);

}

void set_initial_positions(){
  SERVO1.write(THETA1_INIT);
  SERVO2.write(THETA2_INIT);
  SERVO3.write(THETA3_INIT);
  SERVO4.write(THETA4_INIT);
  SERVO5.write(THETA5_INIT);
  SERVO6.write(THETA6_INIT);
  SERVO7.write(THETA7_INIT);
  SERVO8.write(THETA8_INIT);
  SERVO9.write(THETA9_INIT);
  SERVO10.write(THETA10_INIT);
  SERVO11.write(THETA11_INIT);
  SERVO12.write(THETA12_INIT);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial.begin(9600);

  SERVO1.attach(SERVO1_PIN);
  SERVO2.attach(SERVO2_PIN);
  SERVO3.attach(SERVO3_PIN);
  SERVO4.attach(SERVO4_PIN);
  SERVO5.attach(SERVO5_PIN);
  SERVO6.attach(SERVO6_PIN);
  SERVO7.attach(SERVO7_PIN);
  SERVO8.attach(SERVO8_PIN);
  SERVO9.attach(SERVO9_PIN);
  SERVO10.attach(SERVO10_PIN);
  SERVO11.attach(SERVO11_PIN);
  SERVO12.attach(SERVO12_PIN);

  // set an initial position
  Serial.println("Setting initial servo positions:");
  
  set_initial_positions(); // perform initial movement
  
  delay(2000);
}

void loop() {
  if(BTserial.available()>0){
    command = BTserial.read();
    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(command == '1'){
      front_right_back_left_1();  // execute the desired trajectory
      Serial.println("front right back left 1");
    }
    if(command == '2'){
      front_right_back_left_2();  // execute the desired trajectory
      Serial.println("front right back left 2");
    }
    if(command == '3'){
      front_right_back_left_3();  // execute the desired trajectory
      Serial.println("front right back left 3");
    }
    if(command == '4'){
      front_right_back_left_4();  // execute the desired trajectory
      Serial.println("front right back left 4");
    }
    if(command == '5'){
      front_left_back_right_1();  // execute the desired trajectory
      Serial.println("front left back right 1");
    }
    if(command == '6'){
      front_left_back_right_2();  // execute the desired trajectory
      Serial.println("front left back right 2");
    }
    if(command == '7'){
      front_left_back_right_3();  // execute the desired trajectory
      Serial.println("front left back right 3");
    }
    if(command == '8'){
      front_left_back_right_4();  // execute the desired trajectory
      Serial.println("front left back right 4");
    }
    else{
      Serial.println("invalid command");
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }
}