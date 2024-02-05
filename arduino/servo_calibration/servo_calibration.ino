#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
const int SERVO_MIN[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 70, 0};
const int SERVO_MAX[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 470, 450, 450};
bool flag = true;

///////////////////////////// ADJUSTABLE PARAMETERS ////////////////////
////////////////////////////////////////////////////////////////////////
int servonum = 5;
int SERVOMIN = 100;  
int SERVOMAX = 470;  
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


int angle_deg(int servo_no, int angle){
  int angle_degree = map(angle, 0, 180, SERVO_MIN[servo_no], SERVO_MAX[servo_no]);
  return angle_degree; 
}

float angle_rad(int servo_no, int servo_value){
  float angle_radian = map(servo_value, SERVO_MIN[servo_no], SERVO_MAX[servo_no], 0.0, 3.1416);
  return angle_radian; 
}

int angle_to_pwm(int angle_deg){
  return map(angle_deg, 0, 180, SERVOMIN, SERVOMAX);
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
      pwm.setPWM(servonum, 0, angle_to_pwm(0));
      Serial.println("angle: 0");
    }
    else{
      pwm.setPWM(servonum, 0, angle_to_pwm(130));
      Serial.println("angle: 130");
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    while(Serial.available()>0){
      String garbage = Serial.readString();
    }
  }
}