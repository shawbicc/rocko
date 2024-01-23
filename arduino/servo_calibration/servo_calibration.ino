#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
const int SERVO_MIN[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 70, 0};
const int SERVO_MAX[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 470, 450, 450};

///////////////////////////// ADJUSTABLE PARAMETERS ////////////////////
////////////////////////////////////////////////////////////////////////
int servonum = 15;
int SERVOMIN = 70;  
int SERVOMAX = 450;  
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

void setup() {
  Serial.println("Servo Calibration");
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
}


void loop() {
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(2000);

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(2000);

}