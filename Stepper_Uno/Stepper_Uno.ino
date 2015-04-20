#include <Stepper.h>

const int stepsPerRevolution = 200;
int steps = 200;
Stepper myStepper(stepsPerRevolution,8,9,10,11);
int command;
int stopstepper = 1;
int direct = 0;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(60);
  }

void loop() {
  if (Serial.available() > 0){
      command = Serial.read();
      
      if(command == 'S'){
          stopstepper = 1;
      }
      if(command == 'U'){
          direct = 0;
          stopstepper = 0;
      }
      if(command == 'D'){
          direct = 1;
          stopstepper = 0;
      }
  }
  if(!stopstepper){
    if(direct){
      myStepper.step(steps);
    }
    if(!direct){
      myStepper.step(-steps);
    }
  }
}
