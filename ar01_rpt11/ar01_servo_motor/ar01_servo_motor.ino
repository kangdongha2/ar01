#include <Servo.h>

Servo nock_servo;
int degree = 0;

void setup() {
  nock_servo.attach(9); 
  nock_servo.write(degree);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(2) == LOW){
    degree++; 
    if(degree > 180) degree = 180; 
    nock_servo.write(degree); 
    delay(2); 
  }
  if(digitalRead(3) == LOW){
    degree--; 
    if(degree < 0) degree = 0;
    nock_servo.write(degree);
    delay(2); 
  }
}
