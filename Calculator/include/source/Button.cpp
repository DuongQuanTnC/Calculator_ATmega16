/*
 * Button.cpp
 *
 * Created: 27/04/2024 23:42:32
 *  Author: duong
 */ 
#include "Button.h"

unsigned char keypad_button_pressed[BUTTON_COUNT];
unsigned char keypad[6][4];


void keypad_reset_output() {
	// configure pull down | cac chan cot ve 0
	PORTB &= ~(1<<3) &~(1<<4) &~(1<<5)  &~(1<<6);
}

void clear_buttons() {
	for (int i = 0; i < BUTTON_COUNT; i++) {
		keypad_button_pressed[i] = 0;
	}
}

void keypad_setup() {
	// initialize the digital pin as an output:
	DDRA |= (1<<0) | (1<<1) | (1<<2) | (1<<3);
	DDRD &= ~(1<<0) &~(1<<1) &~(1<<2) &~(1<<3) &~(1<<4) &~(1<<5);
	//PORTB |= (1<<3) | (1<<4) | (1<<5) | (1<<6);
	//keypad_reset_output(); //cac chan cot ve 0
	// configure pull ups
	//PORTD &= ~(1<<0) &~(1<<1) &~(1<<2) &~(1<<3)  &~(1<<4) &~(1<<5); //cac chan hang ve 0
	PORTD |= (1<<0) | (1<<1) | (1<<2) | (1<<3)  | (1<<4) | (1<<5);
}


unsigned char keypad_read_buttons() {
	
	unsigned char index;
	unsigned char y = 0; //cot
	
	for (int i = KEYPAD_OUTPUT_BEGIN; i <= KEYPAD_OUTPUT_END; i++) {

		PORTA &= ~(1 << i);
		_delay_ms(10);
		
		unsigned char x = 0; // hang
		
		for (int j = KEYPAD_INPUT_BEGIN; j <= KEYPAD_INPUT_END; j++) {
			
			if  (!(PIND & (1 << j))) {
				
				index = y + (KEYPAD_OUTPUT_END - KEYPAD_OUTPUT_BEGIN + 1) * x; //index = 4x + y
				while (!(PIND & (1 << j)));
				
				return index;
			}
			x++;
		}
		y++;
		PORTA |= (1 << i);
	}
	
	return -1; // No button pressed
}


unsigned char keypad_button_is_pressed() {
	for (int i = 0; i < BUTTON_COUNT; i++) {
		if (keypad_button_pressed[i]) {
			return 1;
		}
	}
	return 0; // no button pressed
}


