/*
 * mylib.cpp
 *
 * Created: 05/05/2024 12:45:32
 *  Author: duong
 */ 

#include "mylib.h"

void clear_string(char *str) {
	*str = '\0';
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void stack_init(Stack *s)
{
	s->top = -1;
}

void stack_push(Stack *s, float value)
{
	if (s->top < STACK_SIZE - 1)
	{
		s->top++;
		s->data[s->top] = value;
	}
}

float stack_top(const Stack *s)
{
	if (s->top >= 0)
	{
		return s->data[s->top];
	}
	else
	{
		return 0;
	}
}

float stack_pop(Stack *s)
{
	float value = 0;
	if (s->top >= 0)
	{
		value = s->data[s->top];
		s->top--;
	}
	return value;
}

void addIntToStringEnd(char *str, uint32_t c) 
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	str[len] = c + '0';
	str[len + 1] = '\0';
}

void addIntToStringStart(char *str, uint32_t c) 
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	for (int i = len ; i >= 0 ; i--)
	{
		str[i+1] = str[i];
	}
	str[0] = c + '0';
	str[len+2] = '\0';
}
void addCharToStringStart(char *str, char c) 
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	for (int i = len ; i >= 0 ; i--)
	{
		str[i+1] = str[i];
	}
	str[0] = c;
	str[len+2] = '\0';
}
void addCharToStringEnd(char *str, char c)
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	str[len] = c;
	str[len + 1] = '\0';
}
float stringToNum(const char* expression)
{
	float result = 0;
	char token;
	int flag = 0;

	while((token = *expression++) != '\0') {
		if(token == ' ')
			continue;
		
		if (token == '-') {
			flag = 1;
		}
		
		if(is_digit(token)) {
			float value = token - '0'; // Chuy?n d?i ký t? s? don thành giá tr? s? nguyên
			//expression++;
			
			while(is_digit(*expression) && *expression) {
				value = value * 10 + (*expression++ - '0'); // Ð?c các ch? s? ti?p theo và c?p nh?t giá tr?
			}
			if (*expression && *expression == '.') {
				expression++;
				
				float decimal = 0.0;
				float decimal_factor = 0.1;
				
				while(is_digit(*expression) && *expression) {
					decimal += (*expression - '0') * decimal_factor;
					decimal_factor *= 0.1;
					expression++;
				}
				value += decimal;
				result = value;
				} else if(token == '.') {
				//expression++;
				
				float decimal = 0.0;
				float decimal_factor = 0.1;
				
				while(is_digit(*expression) && *expression) {
					decimal += (*expression - '0') * decimal_factor;
					decimal_factor *= 0.1;
					expression++;
				}
				result += decimal;
			}
			result = value;
		}
		if (flag == 1)
		{
			result *= 1;
		}
	}
	return result;
}
void numAllToString (uint64_t num, char *str)
{
	uint32_t temp;
	int flag = 0;
	
	if (num < 0)
	{
		num *= -1;
		flag = 1;
	}
	
	do
	{
		temp = num % 10;
		addIntToStringStart(str, temp);
		num /= 10;
	}
	while (num != 0);
	
	if (flag == 1) 
	{
		addCharToStringStart(str, '-');
	}
}

void numAllToString(double num, char *str)
{
	uint64_t integer;
	double decimal;
	uint64_t temp;
	int flag = 0;
	
	if (num < 0)
	{
		num *= -1;
		flag = 1;
	}
	
	integer = (uint64_t)num;
	decimal = num - integer;
	
	do
	{
		temp = integer % 10;
		integer = (integer - temp) / 10;
		addIntToStringStart(str, temp);
	}
	while (integer != 0);
	
	if (decimal != 0) 
	{
		addCharToStringEnd(str, '.');
	}
	
	int cout = 0;
	
	while (decimal >= 0.0001)
	{
		decimal *= 10;
		addIntToStringEnd(str, (uint64_t)decimal);
		decimal -= (uint64_t)decimal;
		
		cout++;
		
 		if (cout == 5)
 		{
 			break;
 		}
 	}
	
	if (flag == 1)
	{
		addCharToStringStart(str, '-');
	}
}

void numToString(double num, char *str)
{
	if (num - (uint64_t)num == 0.0)
	{
		numAllToString((uint64_t)num, str);
	}
	else
	{
		numAllToString(num, str);
	}
}
void clear_last(char *str) { // xoa ky tu cuoi
	if (str[0] == '\0') {
		return;
	}

	uint16_t length = 0;
	while (str[length] != '\0') {
		length++;
	}
	
	if (length >= 1) {
		str[length-1] = '\0';
	}
}

void clear_start(char *str)
{
	if (str[0] == '\0') {
		return;
	}

	int16_t length = 0;
	while (str[length] != '\0') {
		length++;
	}

	for (int i = 0 ; i < length -1 ; i++)
	{
		str[i] = str[i+1];
	}
	str[length-1] = '\0';
}


uint16_t stringlen(const char *str) {
	uint16_t length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

void coppyString(char *cop, const char *str) {
	int i = 0;
	while (str[i] != '\0') {
		cop[i] = str[i];
		i++;
	}
	cop[i] = '\0'; // ??m b?o k?t thúc chu?i ?ích
}