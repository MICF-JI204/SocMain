#include <Stepper.h>

const int stepsPerRevolution = 200;
int steps = 200;
Stepper myStepper(stepsPerRevolution,8,9,10,11);
//int command;
//int stopstepper = 1;
//int direct = 0;

void setup() {
	//Serial.begin(9600);
	myStepper.setSpeed(60);
	pinMode(6,INPUT);
	pinMode(7,INPUT);
	}

void loop() {
    //if (Serial.available() > 0){
        //command = Serial.read();
        /*
        //if(command == 'S'){
	if (digitalRead(6) == 1){
            stopstepper = 1;
        }
	else{
	    stopstepper = 0;
	}
		//if(command == 'U'){
	if (digitalRead(7) == 0){
            direct = 0;
            stopstepper = 0;
        }
        //if(command == 'D'){
	else{
            direct = 1;
            stopstepper = 0;
        }
    //}*/
    if(digitalRead(6)){
        if(digitalRead(7)){
	    myStepper.step(steps);
	}
	else{
	    myStepper.step(-steps);
	}
    }
}
