#ifndef _LED_H_
#define _LED_H_

#define REG_GPIOB_MODER (*(volatile uint32_t *) 0x48000400)
#define REG_GPIOC_MODER (*(volatile uint32_t *) 0x48000800)

void led_init(void);
void led_g_on(void);
void led_g_off(void);
typedef enum {LED_BLUE, LED_YELLOW, LED_OFF} state ;
void led(state);

#endif
