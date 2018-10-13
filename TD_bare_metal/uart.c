#include "stm32l4xx.h"

void uart_init(void);

void uart_init(){
	//Activation horloge port B
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
	//Passage en mode Alternate function PB7 10 RX
	MODIFY_REG(GPIOB->MODER, GPIO_MODER_MODE7_0, GPIO_MODER_MODE7_1);
	//Passage en mode Alternate function PB6 10 TX
	MODIFY_REG(GPIOB->MODER, GPIO_MODER_MODE6_0, GPIO_MODER_MODE6_1);	
	//Activation registre AFRL
	//A FAIRE	
	MODIFY_REG(GPIOB->ARFL, GPIO_MODER_MODE14_1, GPIO_MODER_MODE14_0);	
	//Activation de l'horloge de USART1
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
	//Specifier l'horloge de USART1 en PCLK 00
	CLEAR_BIT(RCC->CCIPR, (RCC_CCIPR_USART1SEL_1 | RCC_CCIPR_USART1SEL_0));	


}
