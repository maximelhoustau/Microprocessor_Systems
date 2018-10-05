MEMORY
{
 rom (rx) : ORIGIN = 0x00000000, LENGTH = 1M
 sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
 sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
 }

_stack = ORIGIN(sram2)+LENGTH(sram2);
_bss = ORIGIN(sram1);
_bss_size = _bss + LENGTH(sram1);

 SECTIONS
 {
  .text : {
    *(.text)
    } > sram1
  .rodata : {
    *(.rodata)
    } > sram1
  .data  : {
    *(.data)
    } > sram1
  .bss  : {
    *(.bss) *(COMMON)
    } > sram1
 }

ENTRY(_start)
