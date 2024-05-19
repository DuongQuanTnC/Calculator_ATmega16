/*
 * LCD.h
 *
 * Created: 24/04/2024 12:31:39
 *  Author: duong
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_DATA_PORT			PORTC
#define LCD_DATA_DDR			DDRC
#define LCD_CONTROL_PORT		PORTB
#define LCD_CONTROL_DDR			DDRB
#define LCD_RS					2
#define LCD_RW					1
#define LCD_E					0

void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init();
void LCD_clear();
void LCD_gotoxy(unsigned char x, unsigned char y);
void LCD_print(const char *str);
void LCD_print_char(char str);
void LCD_print_result(const char *str);
void LCD_print_last(const char *str);

#endif /* LCD_H_ */