#include <stdint.h>

extern uint8_t  _data, _data_LMA, _data_end, _bss, _bss_LMA, _bss_end, _text, _text_LMA, _text_end, _vector_table, _vector_table_LMA, _vector_table_end;

void init_bss(void);
void recopie(void);

//Mise à zero de la section .bss
void init_bss(){
  for ( uint8_t * dst = (uint8_t *) &_bss; dst < (uint8_t *) &_bss_end; dst++)
    *dst = 0;
}

//Recopie des sections en RAM
void recopie(){
	uint8_t * data_LMA = (uint8_t *) &_data_LMA;
	uint8_t * text_LMA = (uint8_t *) &_text_LMA;
	uint8_t * vector_table_LMA = (uint8_t *) &_vector_table_LMA;
	for (uint8_t * dst = (uint8_t *) &_data; dst < (uint8_t *) &_data_end; dst++){
		*dst = * data_LMA++;
	}
	for (uint8_t * dst = (uint8_t *) &_text; dst < (uint8_t *) &_text_end; dst++){
		*dst = *text_LMA++;
	}
	for (uint8_t * dst = (uint8_t *) &_vector_table; dst < (uint8_t *) &_vector_table_end; dst++){
		*dst = *vector_table_LMA++;
	}	

}
