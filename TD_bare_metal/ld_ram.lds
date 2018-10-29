MEMORY
{
 rom (rx) : ORIGIN = 0x00000000, LENGTH = 1M
 sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
 sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
 }

 SECTIONS
 {
.INTERRUPT_TABLE : {
	_vector_table = . ;
	irq.o(.INTERRUPT_TABLE)
	_vector_table_end = . ;
	} > rom AT > sram1
.text : {
	_text = .;
	*(.text) 
	_text_end = . ;
	} > rom AT > sram1
.rodata : {
	*(.rodata)
    } > rom
.data  : {
    	_data = . ;
    	*(.data)
	_data_end = . ;
    } > rom AT > sram1
.bss  : {
	 _bss = . ;
	*(.bss) *(COMMON)
    	_bss_end = . ;
    } > rom AT > sram1
 }

ENTRY(_start)
_stack = ORIGIN(sram2)+LENGTH(sram2) ;
_vector_table_LMA = ORIGIN(.INTERRUPT_TABLE);
_text_LMA = ORIGIN(.text);
_data_LMA = ORIGIN(.data);
_bss_LMA = ORIGIN(.bss);


