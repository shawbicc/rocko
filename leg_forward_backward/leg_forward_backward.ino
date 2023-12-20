#include <Servo.h>

Servo shoulder_servo;
Servo angle1_servo;
Servo angle2_servo; 
Servo gripper_servo;

///////////////////////// CHANGE PIN NUMBERS //////////////////////////
const int shoulder_servo_pin = 9;
const int servo1_pin = 10;
const int servo2_pin = 11;
const int gripper_pin = 12;
//////////////////////////////////////////////////////////////////////
////////////////////////// SET ARM LENGTHS ///////////////////////////
const float l1 = 3.0;
const float l2 = 4.0;
//////////////////////////////////////////////////////////////////////
float theta1 = 0.0;
float theta2 = 0.0;
bool flag = false;
const float step_length = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  shoulder_servo.attach(shoulder_servo_pin);
  angle1_servo.attach(servo1_pin);
  angle2_servo.attach(servo2_pin);
  gripper_servo.attach(gripper_pin);


}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){

    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(flag){
      digitalWrite(LED_BUILTIN, HIGH);
      
      gripper_servo.write(180); //////////// ADJUST ANGLE ///////////////
      delay(500);
      gripper_servo.write(0);
      delay(500);
      
      for (theta1 = 0; theta1 <= 180; theta1 += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        angle1_servo.write(theta1);              // tell servo to go to position in variable 'theta1'
        theta2 = (asin(l1*sin(theta1)/l2) + theta1) * 180/3.1416;
        angle2_servo.write(theta2);
        shoulder_servo.write(theta1);
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
      
    }
    else{
      digitalWrite(LED_BUILTIN, LOW);
//      gripper_servo.write(0); //////////// ADJUST ANGLE ///////////////
//      delay(300);
      
      gripper_servo.write(180); //////////// ADJUST ANGLE ///////////////
      delay(500);
      gripper_servo.write(0);
      delay(500);
      
      for (theta1 = 180; theta1 >= 0; theta1 -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        angle1_servo.write(theta1);              // tell servo to go to position in variable 'theta1'
        theta2 = (asin(l1*sin(theta1)/l2) + theta1) * 180/3.1416;
        angle2_servo.write(theta2);
        shoulder_servo.write(theta1);
        delay(15);                       // waits 15 ms for the servo to reach the position
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    while(Serial.available()>0){
      String garbage = Serial.readString();
    }
  } 
}