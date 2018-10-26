MEMORY
{
 rom (rx) : ORIGIN = 0x00000000, LENGTH = 1M
 sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
 sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
 }

_stack = ORIGIN(sram2)+LENGTH(sram2) ;

 SECTIONS
 {
.INTERRUPT_TABLE : {
	vector_table = . ;
	irq.o(.INTERRUPT_TABLE)
	} >sram1
.text : {
	*(.text) } > sram1
.rodata : {
	*(.rodata)
    } > sram1
.data  : {
    	_data = . ;
    	*(.data)
    } > sram1
.bss  : {
	 _bss = . ;
	*(.bss) *(COMMON)
    	_bss_size = . ;
    } > sram1
 }

ENTRY(_start)
