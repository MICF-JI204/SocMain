#include <Stepper.h>

#define Stepper_IO1 5
#define Stepper_IO2 6
#define Stepper_IO3 12
#define Stepper_IO4 13

int stepsPerRevolution = 200;
int steps = 100;
Stepper myStepper(stepsPerRevolution,8,9,10,11);
//int command;
//int stopstepper = 1;
//int direct = 0;

void setup() {
	//Serial.begin(9600);
	myStepper.setSpeed(90);
	pinMode(3,INPUT);
	pinMode(4,INPUT);

	pinMode(Stepper_IO1,OUTPUT);
	pinMode(Stepper_IO2,OUTPUT);
	pinMode(Stepper_IO3,OUTPUT);
	pinMode(Stepper_IO4,OUTPUT);
	
	digitalWrite(Stepper_IO1,LOW);
	digitalWrite(Stepper_IO2,LOW);
	digitalWrite(Stepper_IO3,LOW);
	digitalWrite(Stepper_IO4,LOW);
	
	}

void loop() {

    if(digitalRead(3)){
		
		digitalWrite(Stepper_IO1,HIGH);
		digitalWrite(Stepper_IO2,HIGH);
		digitalWrite(Stepper_IO3,HIGH);
		digitalWrite(Stepper_IO4,HIGH);
		
        if(digitalRead(4))
		{
			myStepper.step(steps);
		}
		else
		{
			myStepper.step(-steps);
		}
	
		digitalWrite(Stepper_IO1,LOW);
		digitalWrite(Stepper_IO2,LOW);
		digitalWrite(Stepper_IO3,LOW);
		digitalWrite(Stepper_IO4,LOW);
	
    }
}
