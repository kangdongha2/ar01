#include <Stepper.h>
int stepsPerRev = 2048;
Stepper stepper (stepsPerRev, 11,9,10,8);
int swInput1 = 7;
int swInput2 = 7;
int swInput3 = 0;
void setup() {
 stepper.setSpeed(10);
 pinMode(swInput1, INPUT_PULLUP);
 pinMode(swInput2, INPUT_PULLUP);
 pinMode(swInput3, INPUT_PULLUP);
}

void loop() {
 boolean swInput1 = digitalRead(swInput1);
 boolean swInput2 = digitalRead(swInput2);
 boolean swInput3 = digitalRead(swInput3);
 if(swInput1 == LOW){
   stepper.step(1);
 }
 if(swInput2 == LOW){
   stepper.step(-1);
 }
 if(swInput3 == LOW){
   stepper.step(0);
 }
}
