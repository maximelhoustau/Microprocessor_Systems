#ifndef _LED_H_
#define _LED_H_

#define REG_CLOCK_GPIO (*(volatile uint32_t *) 0x4002104C)
#define REG_GPIOB_MODER (*(volatile uint32_t *) 0x48000400)
#define REG_GPIOC_MODER (*(volatile uint32_t *) 0x48000800)
#define REG_GPIOB_BSSR (*(volatile uint32_t *) 0x48000418)
#define REG_GPIOC_BSSR (*(volatile uint32_t *) 0x48000818)

void led_init(void);
void led_g_on(void);
void led_g_off(void);
typedef enum {LED_BLUE, LED_YELLOW, LED_OFF} state ;
void led(state);

#endif
