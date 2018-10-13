#include "led.h"
#include "clocks.h"
#include "uart.h"

int fibo(int n);
void wait(int n);

//Calcul des termes de la suite de Fibonacci
int fib(int n){
  	if (n < 2)
    		return n;
 	 else
    		return fib(n-1) + fib(n-2);
}

//Permet de voir clignoter les leds
void wait(int n){
	for(int i=0; i<n; i++){
		asm volatile("nop");
	}
}

int main(){
	//Test de toutes les fonctions
	uart_init();
	clocks_init();
	led_init();
  	led_g_on();
	led_g_off();
	led(LED_BLUE);
	led(LED_YELLOW);
	led(LED_OFF);
	//Puis test du clignotage
	while(1){
		led_g_on();
		wait(5000000);
		led_g_off();
		led(LED_BLUE);
		wait(5000000);
		led(LED_YELLOW);
		wait(5000000);
		led(LED_OFF);
		wait(5000000);
	}
	return 0;
}
