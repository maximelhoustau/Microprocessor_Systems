#include <stdint.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"

int fibo(int n);
void wait(int n);
uint8_t test;

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
	clocks_init();
	uart_init();
	uart_putchar(100);
	test = uart_getchar();	
	return 0;
}
