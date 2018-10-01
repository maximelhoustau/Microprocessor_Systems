MEMORY
{
//Mapping memory given
 rom (rx) : ORIGIN = 0x00000000, LENGTH = 1M
 sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
 sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
 }
