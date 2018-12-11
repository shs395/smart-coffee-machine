#include "servo.h"
#include "button.h"
#include "buzzer.h"
#include "lcd.h"
#include "sp_pir_app.h"
#include "pir.h"
#include "led.h"

#define BUTTON 1 
#define ON 1
#define PIR 0
#define OFF 0
#define DARK 1
#define LIGHT 2

int main() {
	int state, input;
	state = LIGHT;
	

	coffeesetup();
	watersetup();
	stirsetup();
	lcdsetup();
	
	while(1) {
		if(state == DARK) lcdprint("Coffee", "DARK");
		if(state == LIGHT) lcdprint("Coffee", "LIGHT");

		while(1) {
			if(button()) {
				while(button());
				input = BUTTON;
				printf("button\n");
				break;
			}
			if(pir()) {
				input = PIR;
				printf("pir\n");
				break;
			}
			delay(100);
		}

		if(input == BUTTON){
			if (state == DARK)
				state = LIGHT;
			else if (state == LIGHT)
				state = DARK;
		}
		else if(input == PIR) {
			lcdprint("PIR Detected", "Coffee Making");
			water(state);
			delay(500);
			coffee(state);
			delay(500);
			stir();

			buzzer(0);
			lcdprint("Coffee", "Completed");
			delay(3000);
			buzzer(1);
			delay(3000);
		}
	}

	return 0;
}
