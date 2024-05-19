/*
 * LCD.cpp
 *
 * Created: 24/04/2024 12:32:17
 *  Author: duong
 */ 
#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>

void LCD_command(unsigned char command) {
	LCD_DATA_PORT = command;
	LCD_CONTROL_PORT &= ~(1 << LCD_RS);//RS xuong 0 de ghi lenh
	LCD_CONTROL_PORT &= ~(1 << LCD_RW);//RW xuong 0 de ghi lenh
	//_delay_ms(1);
	//LCD_DATA_PORT = command;
	LCD_CONTROL_PORT |= (1 << LCD_E);
	_delay_ms(1);
	LCD_CONTROL_PORT &= ~(1 << LCD_E);
	_delay_ms(2);
}

void LCD_data(unsigned char data) {
	LCD_DATA_PORT = data; //gui du lieu den cha
	LCD_CONTROL_PORT |= (1 << LCD_RS); //  RS len 1 de ghi du lieu
	LCD_CONTROL_PORT &= ~(1 << LCD_RW); //  chân RW lên 0 de ghi du lieu
	//_delay_ms(1);
	//LCD_DATA_PORT = data; //gui du lieu den chan
	LCD_CONTROL_PORT |= (1 << LCD_E); // Kich hoat chân E
	_delay_ms(1);
	LCD_CONTROL_PORT &= ~(1 << LCD_E); // tat chan E
	_delay_ms(2);
}

void LCD_init() {
	LCD_DATA_DDR = 0xFF; // output D
	LCD_CONTROL_DDR |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_E);
	
	LCD_command (0x38);	
	_delay_ms(1);
	LCD_command (0x0C);
// 	LCD_command (0x06);
// 	_delay_ms(3);	
	_delay_ms(1);
	LCD_command (0x01);
	_delay_ms(1);
	LCD_command (0x80);
	_delay_ms(1);
}

void LCD_clear() {
	LCD_command(0x01); // xoa man hinh
	_delay_ms(1);
	LCD_command(0x80);
	_delay_ms(1);
}

void LCD_gotoxy(unsigned char x, unsigned char y) {
	if(x > 16 || y > 2) {
		return; // 
	}
	unsigned char address;
	if (y == 1)
	{
		address = 0x80 + x -1;
	}
	else 
	{
		address = 0xC0 + x - 1;
	}

	LCD_command(address);
	_delay_ms(2);  
}


void LCD_print(const char *str) {
	while(*str) {
		LCD_data(*str++);
	}
}
void LCD_print_result(const char *str) {
	int i = 0;
	while(str[i] != '\0') {
		i++;
	}
	while(i > 0) {
		LCD_gotoxy(16- i + 1, 1);
		LCD_data(*str++); 
		i--; 
	}
}

void LCD_print_char(char str) {
		LCD_data(str);
}

void LCD_print_last(const char *str) {
	
	while(*str) {
		LCD_data(*str++);
	}
}

