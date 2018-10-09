#include "led.h"

int fibo(int n);
int test;

//Calcul des termes de la suite de Fibonacci
int fib(int n){
  	if (n < 2)
    		return n;
 	 else
    		return fib(n-1) + fib(n-2);
}

int main() {
	led_init();
	asm volatile("nop");
  	led_g_on();
	asm volatile("nop");
	led_g_off();
	

	return 0;
}
