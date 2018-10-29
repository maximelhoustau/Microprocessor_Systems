#ifndef _MATRIX_H_
#define _MATRIX_H_

#define ROW0(x) 	WRITE_REG(GPIOB->BSRR, x?GPIO_BSRR_BS2:GPIO_BSRR_BR2)
#define ROW1(x) 	WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS15:GPIO_BSRR_BR15)
#define ROW2(x) 	WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS2:GPIO_BSRR_BR2)
#define ROW3(x) 	WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS7:GPIO_BSRR_BR7)
#define ROW4(x) 	WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS6:GPIO_BSRR_BR6)
#define ROW5(x) 	WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS5:GPIO_BSRR_BR5)
#define ROW6(x) 	WRITE_REG(GPIOB->BSRR, x?GPIO_BSRR_BS0:GPIO_BSRR_BR0)
#define ROW7(x) 	WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS3:GPIO_BSRR_BR3)
#define RST(x) 		WRITE_REG(GPIOC->BSRR, x?GPIO_BSRR_BS3:GPIO_BSRR_BR3)
#define SB(x) 		WRITE_REG(GPIOC->BSRR, x?GPIO_BSRR_BS5:GPIO_BSRR_BR5)
#define LAT(x) 		WRITE_REG(GPIOC->BSRR, x?GPIO_BSRR_BS4:GPIO_BSRR_BR4)
#define SCK(x)	 	WRITE_REG(GPIOB->BSRR, x?GPIO_BSRR_BS1:GPIO_BSRR_BR1)
#define SDA(x) 		WRITE_REG(GPIOA->BSRR, x?GPIO_BSRR_BS4:GPIO_BSRR_BR4)
#define pulse_SCK() \
	do { \
		SCK(0); \
		wait(3); \
		SCK(1); \
		wait(3); \
		SCK(0); \
		wait(3); } \
	while(0)

#define pulse_LAT() \
	do { \
		LAT(1); \
		wait(3); \
		LAT(0); \
		wait(1); \
		LAT(1); \
		wait(3); } \
	while(0)

//Définition du type pour un pixel
typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;

//Definition du type pour les pixels envoyés au port série
//Variable partagée, position pour connaitre le pixel dans lequel on écrit
typedef struct __attribute__((__packed__)){
	rgb_color pixels[64];
	int position;
} frame;

void matrix_init(void);
void init_bank0(void);
void mat_set_row(int row, const rgb_color *val);
void test_pixels(void);
void display(rgb_color * frame);

extern frame current_frame;

#endif
