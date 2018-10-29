#ifndef _UART_H_
#define _UART_H_

void uart_init(int baudrate);
void uart_puts(const uint8_t *s);
void uart_gets(uint8_t *s, size_t size);
uint32_t checksum(void);
void frame_init(void);

#endif
