/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo s1;
Servo s2; 
Servo s3; 
Servo s4; 
Servo s5; 
Servo s6; 
Servo s7; 
Servo s8; 
Servo s9; 
Servo s10; 
Servo s11;
Servo s12;   // create servo object to control a servo
// twelve servo objects can be created on most boards
    // variable to store the servo position

void setup() {
  s1.attach(3); 
  s2.attach(5); 
  s3.attach(6); 
  s4.attach(9); 
  s5.attach(10); 
  s6.attach(11); 
  s7.attach(A0); 
  s8.attach(A1); 
  s9.attach(A2); 
  s10.attach(A3); 
  s11.attach(A4); 
  s12.attach(A5);   // attaches the servo on pin 9 to the servo object
 
}

void loop() {
   s1.write(30);
  s2.write(10);
  s3.write(90);
  s4.write(30);
  s5.write(50);
  s6.write(90);
  s7.write(30);
  s8.write(10);
  s9.write(90);
  s10.write(30);
  s11.write(50);
  s12.write(90);
}
