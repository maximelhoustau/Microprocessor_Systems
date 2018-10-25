#include <stdint.h>
#include "stm32l4xx.h"
#include "matrix.h"
#include "main.h"

frame current_frame;

void matrix_init(){
	    // Set output pins to high speed mode
    	MODIFY_REG(GPIOA->OSPEEDR, 0, GPIO_OSPEEDR_OSPEED2_Msk | GPIO_OSPEEDR_OSPEED3_Msk |
               GPIO_OSPEEDR_OSPEED4_Msk | GPIO_OSPEEDR_OSPEED5_Msk |
               GPIO_OSPEEDR_OSPEED6_Msk | GPIO_OSPEEDR_OSPEED7_Msk |
               GPIO_OSPEEDR_OSPEED15_Msk);

    	MODIFY_REG(GPIOB->OSPEEDR, 0,
               GPIO_OSPEEDR_OSPEED0_Msk | GPIO_OSPEEDR_OSPEED1_Msk | GPIO_OSPEEDR_OSPEED2_Msk);

    	MODIFY_REG(GPIOC->OSPEEDR, 0,
               GPIO_OSPEEDR_OSPEED3_Msk | GPIO_OSPEEDR_OSPEED4_Msk | GPIO_OSPEEDR_OSPEED5_Msk);
	//Activation des horloges des ports A, B et C
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN);
	//Activation des différentes broches PC3,4,5 PB0,1,2 PA2,3,4,5,6,7,15
	MODIFY_REG(GPIOA->MODER, GPIO_MODER_MODE2_1 | GPIO_MODER_MODE3_1 | GPIO_MODER_MODE4_1 | GPIO_MODER_MODE5_1 | GPIO_MODER_MODE6_1 | GPIO_MODER_MODE7_1 | GPIO_MODER_MODE15_1 , GPIO_MODER_MODE2_0 | GPIO_MODER_MODE3_0 | GPIO_MODER_MODE4_0 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER15_0);
	MODIFY_REG(GPIOB->MODER, GPIO_MODER_MODE0_1 | GPIO_MODER_MODE1_1 | GPIO_MODER_MODE2_1, GPIO_MODER_MODE0_0 | GPIO_MODER_MODE1_0 | GPIO_MODER_MODE2_0);
	MODIFY_REG(GPIOC->MODER, GPIO_MODER_MODE3_1 | GPIO_MODER_MODE4_1 | GPIO_MODER_MODE5_1, GPIO_MODER_MODE3_0 | GPIO_MODER_MODE4_0 | GPIO_MODER_MODE5_0);
	//Mise aux bons états des différentes broches
	SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR3 | GPIO_BSRR_BS4 | GPIO_BSRR_BS5);
	SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR4 | GPIO_BSRR_BR15 |GPIO_BSRR_BR2 |GPIO_BSRR_BR7 |GPIO_BSRR_BR6 |GPIO_BSRR_BR5 |GPIO_BSRR_BR3);
	SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR1 | GPIO_BSRR_BR2 | GPIO_BSRR_BR0);
	wait(10000);
	SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS3);	
	init_bank0();
}

void deactivate_rows(){
	ROW0(0);
	ROW1(0);
	ROW2(0);
	ROW3(0);
	ROW4(0);
	ROW5(0);
	ROW6(0);
	ROW7(0);
}

void activate_rows(int row){
	switch(row){
		case 0: ROW0(1); break;
		case 1: ROW1(1); break;
		case 2: ROW2(1); break;
		case 3: ROW3(1); break;
		case 4: ROW4(1); break;
		case 5: ROW5(1); break;
		case 6: ROW6(1); break;
		case 7: ROW7(1); break;
		default: deactivate_rows();
	}	
}

void send_byte(uint8_t val, int bank){
	SB(bank);
	for(int i= bank?7:5; i>=0; i--){
		SDA(val & (1<<i));
		pulse_SCK();
	}	
}

void mat_set_row(int row, const rgb_color *val){
	for(int i=7; i>=0;i--){
		send_byte(val[i].b, 1);
		send_byte(val[i].g, 1);
		send_byte(val[i].r, 1);
	}
	deactivate_rows();
	activate_rows(row);
	pulse_LAT();
}

void init_bank0(){
	for(int i=0; i<24;i++){
		send_byte(0xff, 0);
	}
	pulse_LAT();
}

void test_pixels(){
	rgb_color reds[8];
	rgb_color blues[8];
	rgb_color greens[8];
	for(int i=0;i<8;i++){
		reds[i].r = ((0xff)>>i);
		blues[i].b = ((0xff)>>i);
		greens[i].g = ((0xff)>>i);
		reds[i].b = 0;
		reds[i].g = 0;
		blues[i].r = 0;
		blues[i].g = 0;
		greens[i].r = 0;
		greens[i].b = 0;
	}
	for(int i=0;i<8;i++){
		mat_set_row(i,reds);
		wait(1000000);
		mat_set_row(i,blues);
		wait(1000000);
		mat_set_row(i,greens);
		wait(1000000);		
	}
}

void display(rgb_color * frame){
	for(int i=0;i<8;i++){
		mat_set_row(i, frame+(8*i));
	}
}

