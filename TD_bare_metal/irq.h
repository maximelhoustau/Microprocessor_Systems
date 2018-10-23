#ifndef _IRQ_H_
#define _IRQ_H_

#define MAKE_DEFAULT_HANDLER(handler) \
	do {\
		void __attribute__((weak)) handler(){\
			__disable_irq();\
			while(1)\
		}\
	}\
	while(0)
	

#endif
