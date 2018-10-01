MEMORY
{
 rom (rx) : ORIGIN = 0x00000000, LENGTH = 1M
 sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
 sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
 }

 SECTIONS
 {
  .text : {
    *(.text)
    } > sram1
  .rodata : AT (ADDR(.text) + SIZEOF(.text)){
    *(.rodata)
    }
  .data 0x2000 : {
    *(.data)
    } AT> sram1
  .bss 0x3000 : {
    *(.bss) *(COMMON)
    }
 }
 ENTRY(main)
