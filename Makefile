all : objs flash

PREFIX:=riscv-none-embed
TARGET_MCU?=CH32V003

TARGET:=exp
TARGET_EXT?=o

ADDITIONAL_C_FILES:= vga.o

CH32V003FUN=./ch32v003fun/ch32v003fun
include $(CH32V003FUN)/ch32v003fun.mk


objs : main.c vga.S
	echo "#ifndef $(TARGET_MCU)\n#define _FUNCONFIG_H\n#define $(TARGET_MCU)\n#endif\n" > funconfig.h
	$(PREFIX)-gcc -c -o $(TARGET).o main.c $(CFLAGS)
	$(PREFIX)-as -o vga.o vga.S -march=rv32ec -mabi=ilp32e

flash : cv_flash
clean : cv_clean
	rm -rf funconfig.h $(TARGET).o vga.o

