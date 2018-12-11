
main : main.o servo_water.o servo_coffee.o button.o buzzer.o lcd.o sp_pir_app.o servo_stir.o led.o
	gcc -o main main.o servo_water.o servo_coffee.o button.o buzzer.o lcd.o sp_pir_app.o servo_stir.o led.o  -lwiringPi -lwiringPiDev


sp_pir_app.o : sp_pir_app.c
	gcc -c sp_pir_app.c


main.o : main.c
	gcc -c main.c

lcd.o : lcd.c
	gcc -c lcd.c

buzzer.o : buzzer.c
	gcc -c buzzer.c

servo_water.o : servo_water.c
	gcc -c servo_water.c

servo_coffee.o : servo_coffee.c
	gcc -c servo_coffee.c

servo_stir.o : servo_stir.c
	gcc -c servo_stir.c

button.o : button.c
	gcc -c button.c
led.o : led.c
	gcc -c led.c
clean :
	rm *.o main
