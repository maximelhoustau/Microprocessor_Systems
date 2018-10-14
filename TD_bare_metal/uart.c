#include <stdint.h>
#include <stddef.h>
#include "stm32l4xx.h"
#include "uart.h"

void uart_init(){
	//Activation horloge port B
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
	//Passage en mode Alternate function PB7 10 RX
	MODIFY_REG(GPIOB->MODER, GPIO_MODER_MODE7_0, GPIO_MODER_MODE7_1);
	//Passage en mode Alternate function PB6 10 TX
	MODIFY_REG(GPIOB->MODER, GPIO_MODER_MODE6_0, GPIO_MODER_MODE6_1);	
	//Activation registre AFRL mode AF7 pour PB6 et PB7
	WRITE_REG( GPIOB->AFR[0] , 0x77000000);
	//Activation de l'horloge de USART1
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
	//Specifier l'horloge de USART1 en PCLK 00
	CLEAR_BIT(RCC->CCIPR, (RCC_CCIPR_USART1SEL_Pos | RCC_CCIPR_USART1SEL_0));	
	//Reset du port APB2
	CLEAR_REG(RCC->APB2RSTR);
	//Configuration de la vitesse 80M/115200=694d=0x2B6
	WRITE_REG(USART1->BRR, 0x2B6);
	//Passage en 8N1 et oversampling à 16 et desactivation de USART1 pour pouvoir effectuer les reglages
	CLEAR_BIT(USART1->CR1, USART_CR1_M0 | USART_CR1_M1 | USART_CR1_PCE | USART_CR1_OVER8 | USART_CR1_UE);
	CLEAR_BIT(USART1->CR2, (USART_CR2_STOP_0 | USART_CR2_STOP_1) );
	//Activation UE, RE, TE
	SET_BIT(USART1->CR1, USART_CR1_UE | USART_CR1_RE | USART_CR1_TE);
}

void uart_putchar(uint8_t c){
	while( ! READ_BIT(USART1->ISR, USART_ISR_TXE ));
	WRITE_REG(USART1->TDR, c);
}

uint8_t uart_getchar(){
	while ( ! READ_BIT( USART1->ISR, USART_ISR_RXNE));
	return  (uint8_t) READ_REG(USART1->RDR) ;
}

void uart_puts(const uint8_t *s){
	while(*s){
		uart_putchar(*s);
		s++;
	}
	uart_putchar('\n');
	uart_putchar('\r');
}

void uart_gets(uint8_t *s, size_t size){
	size_t overrun = 0;
	while ( uart_getchar() != '\n'){
		if (overrun >= size - 1) break;
		*s = uart_getchar();
		s++;
 		overrun++;		
	}
	*s = '\0';

}
