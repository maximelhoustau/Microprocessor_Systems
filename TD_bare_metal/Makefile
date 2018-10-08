CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
CFLAGS = -g -O1
ASFLAGS = -g
TARGET_ARCH = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
TARGET_MACH = $(TARGET_ARCH)
LDFLAGS = -T ld_ram.lds -nostdlib

SOURCES = main.c led.c
OBJS = main.o crt0.o init.o led.o
ASS = crt0.s
LDSCRIPT = ld_ram.lds
EXE = main 

main: main.o crt0.o init.o led.o

START: .gdbinit
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

clean:
	rm -f $(OBJS) $(EXE)
