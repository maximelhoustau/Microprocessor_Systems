#include <stdint.h>
#include <stddef.h>
#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "main.h"
#include "matrix.h"
#include "irq.h"
#include "buttons.h"

size_t const size = 1024;
extern uint8_t _binary_image_raw_start;

//Permet de voir clignoter les leds
void wait(int n){
	for(int i=0; i<n; i++){
		asm volatile("nop");
	}
}

void test_image(){
	rgb_color * start = (rgb_color *)  &_binary_image_raw_start;
	for (int i=0;i<8;i++){
		mat_set_row(i, (rgb_color *)(start+8*i));
		wait(1000);
	}
}

int main(){
	clocks_init();
	matrix_init();
	button_init();
	led_init();
	irq_init();
	frame_init();
	uart_init(38400);
	frame_init();
	while(1){
		display(current_frame.pixels);
	}
	return 0;
}
