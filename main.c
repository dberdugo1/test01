#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
//#include ""

#define BLINK_10HZ			(1000 / 25 / 2)	// 1000ms / 10Hz / 2states
#define TRISPORT			DDRB
#define TRISPIN				DDB5
#define PORT				PORTB
#define PIN					PORTB5

int main(void)
{
//	static bool led = false;

	TRISPORT |= (1 << TRISPIN);
	PORT &= ~(1 << PIN);

	while(1)
	{
		PORT |= (1 << PIN);
		_delay_ms(BLINK_10HZ);
		PORT &= ~(1 << PIN);
		_delay_ms(BLINK_10HZ);
		PORT |= (1 << PIN);
	}
	return 0;
}
