#ifndef _IRQ_H_
#define _IRQ_H_

#define MAKE_DEFAULT_HANDLER(handler) \
		void __attribute__((weak)) handler(){\
			__disable_irq();\
			while(1)}

void irq_init(void);

#endif
