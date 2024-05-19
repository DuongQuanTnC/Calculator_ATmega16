/*
 * Button.h
 *
 * Created: 28/04/2024 00:16:29
 *  Author: duong
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_COUNT 24
#define KEYPAD_OUTPUT_BEGIN 0
#define KEYPAD_OUTPUT_END 3
#define KEYPAD_INPUT_BEGIN 0
#define KEYPAD_INPUT_END 5
#define KEYPAD_NO_BUTTON_PRESSED -1

unsigned char keypad_button_is_pressed();
unsigned char keypad_read_buttons();
void keypad_setup();
void clear_buttons();
void keypad_reset_output();

#endif /* BUTTON_H_ */