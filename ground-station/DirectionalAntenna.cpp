#include "DirectionalAntenna.h"
#include "Configuration.h"

#include <Arduino.h>
#include <Servo.h> 

DirectionalAntenna::DirectionalAntenna() {
  horizontalServo = new Servo;
  horizontalServo->attach(52);
  
  verticalServo = new Servo;
  verticalServo->attach(53);
  
  horizontalServo->write(100);
  verticalServo->write(100);
  
  horizontalServo->write(0);
  verticalServo->write(0);
  delay(500);
  
  horizontalServo->write(180);
  verticalServo->write(180);
}

void DirectionalAntenna::tick() {
}