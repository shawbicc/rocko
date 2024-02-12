#include <Servo.h>

#define SERVO1 3
#define SERVO2 5
#define SERVO3 6
#define SERVO4 9
#define GRIPPER 11

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo gripper;

const int loose = 100;
const int pull = 0; 

bool flag = true;


void push(){
  //servo1.write(90);
  servo2.write(60);
  servo3.write(90);
  //servo4.write(60);
  gripper.write(loose);
  Serial.println("pushed");
}


void zero(){
  servo1.write(90);
  servo2.write(100);
  servo3.write(30);
  servo4.write(60);
  gripper.write(loose);
}

void release(){
  gripper.write(pull);
  delay(1000);
  //servo1.write(30);
  //servo2.write(100);
  servo3.write(30);
  //servo4.write(100);
  gripper.write(loose);
  Serial.println("released");
}

void setup(){
  Serial.begin(9600);
  pinMode(SERVO1, OUTPUT);
  pinMode(SERVO2, OUTPUT);
  pinMode(SERVO3, OUTPUT);
  pinMode(SERVO4, OUTPUT);
  pinMode(GRIPPER, OUTPUT);

  
  servo1.attach(SERVO1);
  servo2.attach(SERVO2);
  servo3.attach(SERVO3);
  servo4.attach(SERVO4);
  gripper.attach(GRIPPER);

  zero();
}



void loop(){
  if(Serial.available()>0){

    /////////////////////////////// do what you gotta do each time there's an input in the serial monitor ////////////////////////////////////
    if(flag){
      push();  // execute the desired trajectory
    }
    else{
      release();  // execute the desired trajectory
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // clear buffer
    flag = !flag;
    while(Serial.available()>0){
      String garbage = Serial.readString();
    }
  }
}