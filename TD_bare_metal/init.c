#include <stdint.h>

extern char _data, _bss, _bss_size;
uint8_t *dst = &_data;

//Mise à zero de la section .bss
void init_bss(){
  for (dst = (uint8_t *) &_bss; dst < (uint8_t *) &_bss_size; dst++)
    *dst = 0;
}
