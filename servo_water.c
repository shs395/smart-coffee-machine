#include "servo.h"
#include <softPwm.h>
#define PIN 2
#define MIN 8000

int watersetup() {
	if(wiringPiSetup() == -1)
		return 1;
	softPwmCreate(PIN, 0 , 200);
	return 0;
}
int water(int ratio) 
{
	softPwmWrite(PIN, 5);
	delay(400);
	softPwmWrite(PIN, 0);
	delay(MIN*ratio);
	softPwmWrite(PIN, 25);
	delay(400);
	return 0;
}
