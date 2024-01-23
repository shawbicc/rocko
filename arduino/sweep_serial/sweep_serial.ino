#include <Servo.h>

/////////////////////////////////// EDIT THIS /////////////////////////////////////
const int servo_pin = 9;
///////////////////////////////////////////////////////////////////////////////////

bool flag = false;
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){

    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(flag){
      myservo.write(180);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else{
      myservo.write(0);
      digitalWrite(LED_BUILTIN, LOW);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    while(Serial.available()>0){
      String garbage = Serial.readString();
    }
  }
}
