#ifndef _LED_H_
#define _LED_H_

void led_init(void);
void led_g_on(void);
void led_g_off(void);
typedef enum {LED_BLUE, LED_YELLOW, LED_OFF} state ;
void led(state);

#endif
