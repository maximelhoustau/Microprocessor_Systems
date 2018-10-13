CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
CFLAGS = -Wall -Werror -Wextra -g -O1 -I./clocks -I./CMSIS/Device/ST/STM32L4xx/Include -I./CMSIS/Include
ASFLAGS = -g
TARGET_ARCH = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
TARGET_MACH = $(TARGET_ARCH)
LDFLAGS = -T ld_ram.lds -nostdlib
CPPFLAGS += -DSTM32L475xx 

SOURCES = main.c led.c
OBJS = main.o crt0.o init.o led.o uart.o
ASS = crt0.s
LDSCRIPT = ld_ram.lds
EXE = main 
VPATH = clocks

main: $(OBJS) clocks.o 

led.o: led.c led.h

start: .gdbinit
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly
pico:
	picocom -b 115200 -f n -p n -d 8 /dev/cu.usbmodem1421
gdb: main
	arm-none-eabi-gdb main

clean:
	rm -f $(OBJS) $(EXE)
