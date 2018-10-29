#include <stdint.h>
#include <stddef.h>
#include "stm32l4xx.h"
#include "uart.h"
#include "matrix.h"

void uart_init(int baudrate){
	//Activation horloge port B 0x4002104C
	SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
	//Passage en mode Alternate function PB7 et PB6 10 RX 0x48000400
	MODIFY_REG(GPIOB->MODER, GPIO_MODER_MODE7_0|GPIO_MODER_MODE6_0, GPIO_MODER_MODE7_1 | GPIO_MODER_MODE6_1 ) ;
	//Activation registre AFRL mode AF7 pour PB6 et PB7 0x48000420
	WRITE_REG( GPIOB->AFR[0] , 0x77000000);
	//Activation de l'horloge de USART1 
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);
	//Specifier l'horloge de USART1 en PCLK 00
	//SET_BIT(USART1->CR2, USART_CR2_CLKEN);
	CLEAR_BIT(RCC->CCIPR, RCC_CCIPR_USART1SEL);	
	//Reset du port APB2
	SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST);
	CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST);
	//Configuration de la vitesse 80M/115200=694d=0x2B6
	WRITE_REG(USART1->BRR, 80000000/baudrate);
	//Initialisation des registres, oversampling à 16 et passage à 8N1
	USART1->CR1 = 0;
	//Activation UE, RE, TE
	SET_BIT(USART1->CR1, USART_CR1_UE | USART_CR1_RE | USART_CR1_TE);
}

//A appeler après uart_init()
void frame_init(){
	current_frame.position = 0;
	//Active les interruptions quand le registre de lecture contient qqchose
	SET_BIT(USART1->CR1, USART_CR1_RXNEIE);
	//Active les IRQ sur USART1
	NVIC_EnableIRQ(USART1_IRQn);
}

static void uart_putchar(uint8_t c){
	while( ! READ_BIT(USART1->ISR, USART_ISR_TXE )) ;
	WRITE_REG(USART1->TDR, c);
}

static uint8_t uart_getchar(){
	while ( ! READ_BIT( USART1->ISR, USART_ISR_RXNE));
	return  (uint8_t) READ_REG(USART1->RDR);
}

void uart_puts(const uint8_t *s){
	while(*s){
		uart_putchar(*s);
		s++;
	}
	uart_putchar('\n');
	uart_putchar('\r');
}

void uart_gets(uint8_t *s, size_t size) {
    uint32_t i = 0 ;
    uint8_t byte = uart_getchar() ;
    while( byte != '\n' && byte != '\r'  && i < size - 1) {
        s[i++] = byte ;
	byte = uart_getchar();
    }
    s[i] = '\0' ;
}

uint32_t checksum(){
	uint32_t sum_size = 1000;
	uint32_t ope = 0;
	uint32_t sum = 0;
	while(ope <sum_size){
		sum += uart_getchar();
		ope++;
	}
	return sum;
}

//Redefinition du Handler sur USART1 pour les envois de trames
void USART1_IRQHandler(){
	uint8_t byte = uart_getchar();
	uint8_t * frame = (uint8_t *) current_frame.pixels;
	
	if (READ_BIT(USART1->ISR, USART_ISR_FE) | READ_BIT(USART1->ISR, USART_ISR_ORE)){
		SET_BIT(USART1->ICR, USART_ICR_ORECF | USART_ICR_FECF);
		current_frame.position =0;
		for(int i=0;i<192;i++){
			frame[i] = 0;
		}	
		return;
	}
	
	else if( byte == 0xff || current_frame.position > 192 ){
		current_frame.position = 0;
	}
	else {
		frame[current_frame.position] = byte;
		current_frame.position++;
	}
	

}

