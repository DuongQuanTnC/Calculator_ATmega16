/*
 * mylib.h
 *
 * Created: 05/05/2024 12:45:47
 *  Author: duong
 */ 


#ifndef MYLIB_H_
#define MYLIB_H_

#include "Calculator.h"
#include "LCD.h"
#include "stdint.h"

struct Stack{
	float data[STACK_SIZE];
	int top;
};

int is_digit(char c);
void numToString(double num, char *str);
void addCharToStringEnd(char *str, char c);
void addIntToStringEnd(char *str, uint32_t c);
void addIntToStringStart(char *str, uint32_t c);
void addCharToStringStart(char *str, char c);
float stringToNum(const char* expression);
void numAllToString (uint64_t num, char *str);
void numAllToString(double num, char *str);
void clear_string(char *str);
void stack_init(Stack *s);
void stack_push(Stack *s, float value);
float stack_top(const Stack *s);
float stack_pop(Stack *s);
void clear_last(char *str);
uint16_t stringlen(const char *str);
void clear_start(char *str);
void coppyString(char *cop, const char *str);



#endif /* MYLIB_H_ */