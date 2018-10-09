#include <stdint.h>
#include "led.h"
#define REG_AHB2_GPIOB (*(volatile uint32_t *)0x4002104C)
#define REG_GPIOB_MODER (*(volatile uint32_t *)0x48000400)
#define REG_GPIOB_BSSR (*(volatile uint32_t *)0x48000418)

//Configuration de la broche B en mode sortie:  GPIOB_MODER reset value: 0xFFFFFEBF MODE14[1:0] = 01;
//registre GPIOB @début: 0x48000400 @fin:  0x480007FF taille 1Kb
//
//Activation de l'horloge:offset: 0x4C pour GPIOB bit 1 à 0/1 pour désactiver/activer
//registre AHB2 activation de l'horloge @début pour GPIOB: 0x48000400
//
void led_init(){
	REG_AHB2_GPIOB |= 0x2	;	
	REG_GPIOB_MODER = (REG_GPIOB_MODER | (1<<28)) & ~(1<<29);
}

void led_g_on(){
	//Mise à 1 du bit n°14: etat haut du port 14
	REG_GPIOB_BSSR |= (1<<14);
}

void led_g_off(){
	//Mise à un 1 du bit n°30: reset du port 14
	REG_GPIOB_BSSR |= (1<<30);
}

