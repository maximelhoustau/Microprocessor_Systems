#ifndef A__H
#define A__H


void led_init(void);
void led_g_on(void);
void led_g_off(void);
void led(state);
enum state {LED_BLUE, LED_YELLOW,LED_OFF};

#endif
