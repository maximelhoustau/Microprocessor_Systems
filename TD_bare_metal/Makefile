CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
CFLAGS = -g -O1
TARGET_ARCH = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS = -T ld_ram.lds -nostdlib

SOURCES = main.c
OBJS = main.o crt0.o
ASS = crt0.s
LDSCRIPT = ld_ram.lds
EXE = main

main: main.o crt0.o

START: .gdbinit
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

clean:
	rm -f $(OBJS) $(EXE)
