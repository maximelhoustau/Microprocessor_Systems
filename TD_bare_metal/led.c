#include <stdint.h>
#include "led.h"
#include "stm32l4xx.h"

//Configuration de la broche B en mode sortie:  GPIOB_MODER reset value: 0xFFFFFEBF MODE14[1:0] = 01;
//registre GPIOB @début: 0x48000400 @fin:  0x480007FF taille 1Kb
//Les GPIO se trouvent dans la partie AHB2
//Activation de l'horloge:offset: 0x4C pour GPIOB bit 1 à 0/1 pour désactiver/activer
//registre AHB2 activation de l'horloge @début pour GPIOB: 0x48000400

void led_init(){
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);	
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);	
	REG_GPIOB_MODER = (REG_GPIOB_MODER | (1<<28)) & ~(1<<29);
}

void led_g_on(){
	//Mise à 1 du bit n°14: etat haut du port 14
	SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS14);
}

void led_g_off(){
	//Mise à un 1 du bit n°30: reset du port 14
	SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR14);
}

void led(state color){
	switch (color){
		case LED_YELLOW:
			REG_GPIOC_MODER = (REG_GPIOC_MODER | (1<<18)) & ~(1<<19);	
			SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS9);
			break;
		case LED_BLUE:
			REG_GPIOC_MODER = (REG_GPIOC_MODER | (1<<18)) & ~(1<<19);
			SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR9);
			break;
		case LED_OFF:
			REG_GPIOC_MODER = (REG_GPIOC_MODER & ~(1<<18)) & ~(1<<19);
			break;
		}
}
