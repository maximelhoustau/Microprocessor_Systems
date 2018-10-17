#include <stdint.h>
#include <stddef.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "main.h"
#include "matrix.h"

size_t size = 1024;
uint32_t test;
extern uint8_t _binary_image_raw_start;

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

void test_image(){
	rgb_color *start = (rgb_color *)  &_binary_image_raw_start;
	for (int i=0;i<8;i++){
		mat_set_row(i, (start+24*i));
		wait(1000);
	}
}

int main(){
	clocks_init();
	matrix_init();
	test_pixels();
	wait(1000000);
	while(1){
		test_image();
	}
	return 0;
}
