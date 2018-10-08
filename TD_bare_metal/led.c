#include <stdint.h>
#include "led.h"
#define REG_AHB2_GPIOB (*(volatile uint32_t *)0x4800004C)
#define REG_GPIOB_MODER (*(volatile uint32_t *)0x48000400)
#define REG_GPIOB_PUPDR (*(volatile uint32_t *)0x4800040C)


void led_g_on(void);
void led_g_off(void);

//Configuration de la broche B en mode sortie:  GPIOB_MODER reset value: 0xFFFFFEBF MODE14[1:0] = 01;
//registre GPIOB @début: 0x48000400 @fin:  0x480007FF taille 1Kb
//
//Activation de l'horloge:offset: 0x4C pour GPIOB bit 1 à 0/1 pour désactiver/activer
//registre AHB2 activation de l'horloge @début: 0x50060C00 @fin: 0x48000000
//
void led_init(){
	REG_AHB2_GPIOB = (REG_AHB2_GPIOB | (1<<1));	
	REG_GPIOB_MODER = (REG_GPIOB_MODER | (1<<29));
}

void led_g_on(){
	REG_GPIOB_PUPDR = (REG_GPIOB_PUPDR & ~(1<<29));
}

void led_g_off(){
	REG_GPIOB_PUPDR = (REG_GPIOB_PUPDR & ~(1<<29));
}

