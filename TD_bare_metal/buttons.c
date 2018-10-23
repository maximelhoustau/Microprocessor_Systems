#include "stm32l4xx.h"
#include "buttons.h"
#include "led.h"
#include "main.h"

void button_init(){
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);
	CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE13_0 | GPIO_MODER_MODE13_1);
	SET_BIT(EXTI->IMR1, EXTI_IMR1_IM13);
	SET_BIT(EXTI->FTSR1, EXTI_FTSR1_FT13);
	CLEAR_BIT(EXTI->RTSR1, EXTI_RTSR1_RT13);
	SYSCFG->EXTICR[3] |= 0x20;	
	NVIC_EnableIRQ(40);
	
}

//Redéfinition de l'interruption sur le handler EXTI15_10
void EXTI15_10_IRQHandler(){
	SET_BIT(EXTI->PR1, EXTI_PR1_PIF13);
	led_g_on();
	wait(1000000);
	led_g_off();
}


