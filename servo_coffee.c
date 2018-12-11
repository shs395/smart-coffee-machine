#include "servo.h"
#include <softPwm.h>

#define PIN 0
#define MIN 8000
int coffeesetup() {
	if(wiringPiSetup() == -1) 
	      return 1;	
	softPwmCreate(PIN, 0, 200);
	return 0;
}

int coffee() 
{
	softPwmWrite(PIN, 3);
	delay(300);
	softPwmWrite(PIN, 0);
	delay(MIN);
	softPwmWrite(PIN ,23);
	delay(300);
	return 0;
}
