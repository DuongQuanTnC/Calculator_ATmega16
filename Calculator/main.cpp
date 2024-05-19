#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "LCD.h"
#include "Button.h"
#include "Calculator.h"
#include "mylib.h"
#include "stdint.h"

char string[30];
char string1[30];
double result;

float memory = 0.0;



// void floatToString(float num, char* str) {
// 	int intPart = (int)num;
// 	int floatPart = (int)((num - intPart) * pow(10, 6));
// 	sprintf(str, "%d.%d", intPart, floatPart);
// }

void printKeypadToLCD() {
	int8_t key;
	int8_t flag = 0;
	keypad_setup();
	
	while (1) {

		key = keypad_read_buttons();
		switch (key) {
			case 0:
			memory = 0;
			// 				clear_last(string);
			// 				LCD_clear();
			// 				_delay_ms(2);
			break;
			case 1:
			clear_string(string);
			LCD_clear();
			_delay_ms(2);
			LCD_print("M");
			clear_string(string);
			numToString(memory,string);
			LCD_print_result(string);
			flag = 1;
			_delay_ms(5);
			break;
			case 2:
			if (checkErrorCalculations(string) == 1)
			{
				LCD_print_result("ERROR");
				_delay_ms(5);
			}
			else
			{
				memory -= stringToNum(string);
				flag = 1;
				LCD_print_result(string);
				_delay_ms(5);
			}
			
			break;
			case 3:
			if (checkErrorCalculations(string) == 1)
			{
				LCD_print_result("ERROR");
				_delay_ms(5);
			}
			else
			{
				memory += stringToNum(string);
				flag = 1;
				LCD_print_result(string);
				_delay_ms(5);
			}
			break;
			case 4:
			clear_string(string);
			clear_string(string1);
			LCD_clear();
			_delay_ms(2);
			break;
			case 5:
			result *= -1;
			LCD_clear();
			_delay_ms(2);
			LCD_print(string1);
			clear_string(string);
			numToString(result, string);
			flag = 1;
			LCD_print_result(string);
			_delay_ms(3);
			break;
			case 6:
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			LCD_print_char(0x25);
			_delay_ms(5);
			addCharToStringEnd(string, 37);
			break;
			case 7:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print_char(0xE8);
			_delay_ms(5);
			addCharToStringEnd(string, 94);
			break;
			case 8:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print_last("7");
			_delay_ms(5);
			addIntToStringEnd(string, 7);
			break;
			case 9:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("8");
			_delay_ms(5);
			addIntToStringEnd(string, 8);
			break;
			case 10:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("9");
			_delay_ms(5);
			addIntToStringEnd(string, 9);
			break;
			case 11:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print_char(0xFD);
			_delay_ms(5);
			addCharToStringEnd(string, 47);
			break;
			case 12:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("4");
			_delay_ms(5);
			addIntToStringEnd(string, 4);
			break;
			case 13:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("5");
			_delay_ms(5);
			addIntToStringEnd(string, 5);
			break;
			case 14:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("6");
			_delay_ms(5);
			addIntToStringEnd(string, 6);
			break;
			case 15:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print_char(0x78);
			_delay_ms(5);
			addCharToStringEnd(string, 42);
			break;
			case 16:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("1");
			_delay_ms(5);
			addIntToStringEnd(string, 1);
			break;
			case 17:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("2");
			_delay_ms(5);
			addIntToStringEnd(string, 2);
			break;
			case 18:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("3");
			_delay_ms(5);
			addIntToStringEnd(string, 3);
			break;
			case 19:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("-");
			_delay_ms(5);
			addCharToStringEnd(string, 45);
			break;
			case 20:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("0");
			_delay_ms(5);
			addIntToStringEnd(string, 0);
			break;
			case 21:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print(".");
			_delay_ms(5);
			addCharToStringEnd(string, 46);
			break;
			case 23:
			if (flag == 1)
			{
				LCD_clear();
				_delay_ms(2);
				clear_string(string);
				clear_string(string1);
				result = 0;
				flag = 0;
			}
			if (stringlen(string) >= 15)
			{
				LCD_command(0x18);
			}
			LCD_print("+");
			_delay_ms(5);
			addCharToStringEnd(string, 43);
			break;
			case 22: // dau bang (=)
			clear_string(string1);
			flag = 1;
			if (checkErrorCalculations(string) == 1)
			{
				LCD_print_result("ERROR");
				_delay_ms(5);
			}
			else
			{
				result = evaluate_expression(string);
				if(result >= power(2,63))
				{
					LCD_print_result("ERROR");
					_delay_ms(5);
				}
				else
				{
					clear_string(string);
					numToString(result, string);
					if(stringlen(string) > 15)
					{
						LCD_print_result("ERROR \0");
						_delay_ms(5);
					}
					else
					{
						coppyString(string1, string); //dung trong truong hop doi dau +-, va nhieu th khac
						LCD_print_result(string);
						_delay_ms(5);
					}
				}
			}
			break;
			default:
			break;
		}
	}
}

int main(void) {
	
	LCD_init(); // Kh?i t?o LCD
	_delay_ms(10);
	// port B
	//keypad_setup(); // Kh?i t?o bàn phím
	
	LCD_gotoxy(16,1);
	LCD_command(0x07);
	printKeypadToLCD();

	
	
	
	// 	LCD_gotoxy(5,1);
	// 	LCD_print("D");
	// 	LCD_gotoxy(3,2);
	// 	LCD_print("DH CONG NGHE");
	
	// 	//keypad_setup();
	// 	while(1) {
	// 		//keypad_read_buttons();
	// 	}
	
	return 0;
}


