#include "ch32v003fun.h"
#include <stdio.h>

#define HSYNC PD0
#define VSYNC PD4
#define LUMA PD5
extern void vga();

int main() {
	int x, y;
	SystemInit();
	funGpioInitAll();

	funPinMode(HSYNC, GPIO_Speed_50MHz | GPIO_CNF_OUT_PP);
	funPinMode(VSYNC, GPIO_Speed_50MHz | GPIO_CNF_OUT_PP);
	funPinMode(LUMA, GPIO_Speed_50MHz | GPIO_CNF_OUT_PP);

	// vga();

	while (1) {
		funDigitalWrite(LUMA, 0);
		funDigitalWrite(VSYNC, 0);
		funDigitalWrite(HSYNC, 0);
		//DelaySysTick(22);
		Delay_Us(3.8);
		funDigitalWrite(HSYNC, 1);
		Delay_Us(28); //27
		funDigitalWrite(HSYNC, 0);
		//elaySysTick(22);
		Delay_Us(3.8);
		funDigitalWrite(HSYNC, 1);
		Delay_Us(28); //27
		funDigitalWrite(VSYNC, 1);
		funDigitalWrite(LUMA, 1);
		for (y = 0; y < 523; y++) {
			funDigitalWrite(HSYNC, 0);
			Delay_Us(3.8);
			//DelaySysTick(22);
			funDigitalWrite(HSYNC, 1);
			//DelaySysTick((28 * ((FUNCONF_SYSTEM_CORE_CLOCK) / 1000000))); //27
			Delay_Us(28);
		}
	}

	// while(1) {
	// 	asm volatile(".word 0xaaaaaaaa\n");
	// 	funDigitalWrite(HSYNC, 1);
	// 	funDigitalWrite(HSYNC, 0);
	// 	asm volatile(".word 0xaaaaaaaa\n");
	// }
}
