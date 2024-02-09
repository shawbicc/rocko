
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
bool flag = false;


// array of max and min pwm values for servos, found from servo_calibration.ino
const int SERVO_MIN[16] = {70, 70, 100, 70, 70, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int SERVO_MAX[16] = {450, 450, 470, 450, 450, 470, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

///////////////////////////// ADJUSTABLE PARAMETERS ////////////////////
////////////////////////////////////////////////////////////////////////
int SERVONUM = 0;
int LOWANGLE = 30;  
int HIGHANGLE = 90;  

const int SERVO_DIR[16] = {1, -1, 1, 0, -1, 1, 1, 0, 1, -1, 1, 0, -1, 1, 1, 0};  // flip direction of servo
//////////////////////     ^f-r      ^f-l            ^b-r          ^b-l
////////////////////////////////////////////////////////////////////////


int angle_deg(int servo_no, int angle){
  int angle_degree = map(angle, 0, 180, SERVO_MIN[servo_no], SERVO_MAX[servo_no]);
  return angle_degree; 
}

float angle_rad(int servo_no, int servo_value){
  float angle_radian = map(servo_value, SERVO_MIN[servo_no], SERVO_MAX[servo_no], 0.0, 3.1416);
  return angle_radian; 
}

// function to convert angle (deg) to pwm; maps min-max to 0-180 by default
int angle_to_pwm(int angle, int servo_idx){
  if(SERVO_DIR[servo_idx] == 1){ return map(angle, 0, 180, SERVO_MIN[servo_idx], SERVO_MAX[servo_idx]);}
  else if(SERVO_DIR[servo_idx] == -1) {return map(angle, 0, 180, SERVO_MAX[servo_idx], SERVO_MIN[servo_idx]);}
  else{ 
    Serial.println("Invalid rotation direction!");
    return ((SERVO_MAX[servo_idx]+SERVO_MIN[servo_idx])/2); // return average if invalid direction  
  };
}

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Calibration");
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
}

void loop() {
  if(Serial.available()>0){

    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(flag){
      pwm.setPWM(SERVONUM, 0, angle_to_pwm(LOWANGLE, SERVONUM));
      Serial.println("Servo " + String(SERVONUM) + " at " + String(LOWANGLE));
    }
    else{
      pwm.setPWM(SERVONUM, 0, angle_to_pwm(HIGHANGLE, SERVONUM));
      Serial.println("Servo " + String(SERVONUM) + " at " + String(HIGHANGLE));
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    while(Serial.available()>0){
      String garbage = Serial.readString();
    }
  }
}