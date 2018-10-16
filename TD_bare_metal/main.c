#include <stdint.h>
#include <stddef.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "main.h"
#include "matrix.h"

size_t size = 1024;
uint32_t test;

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
	//uint8_t s[size];
	uint32_t sum;
	clocks_init();
	uart_init();
	//wait(10000);
	sum = checksum();
	//wait(10000);
	//uart_puts( (const uint8_t *) "Ok\n");
	//uart_puts( (const uint8_t *) sum);
	/*
	while(1){
		uart_gets(s, size);
		uart_puts(s);	
	} */
	return sum;
}
