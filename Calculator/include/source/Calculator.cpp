/*
 * Calculator.cpp
 *
 * Created: 28/04/2024 00:46:19
 *  Author: duong
 */ 

#include "Calculator.h"
#include "LCD.h"
#include "mylib.h"

char str[30];

int precedence(char op) {
	if(op == '+' || op == '-')
		return 1;
	if(op == '*' || op == '/')
		return 2;
	if(op == '^' || op == '%')
		return 3;
	return 0;
}

double performCalculations (double a, double b, char op)
{
	switch(op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return (a / b);
		case '%': return a / 100; // Tính ph?n tram
		case '^': return sqrt_num(b);
	}
	return 0;
}


int checkDivideByZero(double a, double b, char op) {
	if (op == '/' && b == 0)
	{
		return 1;
	}
	return 0;
}

double power(int64_t b, int64_t e) {
	double result = 1;
	for (int i = 0; i < e; ++i) {
		result *= b;
	}
	return result;
}

float sqrt_num(float x) 
{
	float epsilon = 0.00001;
	float guess;
	
	float temp = x / 2.0;
	
	do
	{
		guess = temp;
		temp = (guess + x / guess) / 2.0;
	}
	while (fabs(temp - guess) >= epsilon);
	 
	return temp;
}

double evaluate_expression(const char* expression) {
	Stack values;
	Stack operators;
	stack_init(&values);
	stack_init(&operators);
	
	double result = 0;
	char token;
	
	int flag = 0;
	while((token = *expression++) != '\0')
	{
		if(token == ' ')
		continue;
		if(is_digit(token))
		{
			double value = token - '0'; // Chuy?n d?i ký t? s? don thành giá tr? s? nguyên
			//expression++;
			
			while(is_digit(*expression) && *expression)
			{
				value = value * 10 + (*expression++ - '0'); // Ð?c các ch? s? ti?p theo và c?p nh?t giá tr?
			}
			if (*expression && *expression == '.') {
				expression++;
				
				double decimal = 0.0;
				double decimal_factor = 0.1;
				
				while(is_digit(*expression) && *expression) {
					decimal += (*expression - '0') * decimal_factor;
					decimal_factor *= 0.1;
					expression++;
				}
				value += decimal;
			}
			if (flag == 1)
			{
				value *= -1;
				flag = 0;
			}
			
			stack_push(&values, value);
			
		}
		else if (token == '.')
		{
			double decimal = 0.0;
			double decimal_factor = 0.1;
			
			while(is_digit(*expression) && *expression) {
				decimal += (*expression - '0') * decimal_factor;
				decimal_factor *= 0.1;
				expression++;
			}
			result += decimal;
			if (flag == 1)
			{
				result *= -1;
				flag = 0;
			}
			stack_push(&values, result);
		}
		//}
		//else if (token == '^') {
		//	stack_push(&operators, token);
		
		//else if(token == '(') {
		//    stack_push(&operators, token);
		//
		//} else if(token == ')') {
		//    while(stack_top(&operators) >= 0 && stack_top(&operators) != '(') {
		//        char op = stack_pop(&operators);
		//        double b = stack_pop(&values);
		//        double a = stack_pop(&values);
		//        stack_push(&values, apply_operation(a, b, op));
		//    }
		//    stack_pop(&operators); // Pop '('
		
		else
		{ // Operator
			while(stack_top(&operators) >= 0 && precedence(stack_top(&operators)) >= precedence(token)) {
				char op = stack_pop(&operators);
				double b = stack_pop(&values);
				double a = stack_pop(&values);
				stack_push(&values, performCalculations(a, b, op));
			}
			if (token == '^') {
				//stack_push(&operators, token);
				stack_push(&values, 1);
			}
			if (token == '%')
			{
				stack_push(&values, 1);
			}
			stack_push(&operators, token);
			
			//expression++;
			if (*expression == '-')
			{
				flag = 1;
				expression++;
			}
			else if (*expression == '+')
			{
				expression++;
			}
			else if (is_digit(*expression))
			{
				continue;
			}
			else if (*expression == '/' || *expression == '*')
			{
				return -1;
			}
		}
	}

	while(stack_top(&operators) > 0) {
		char op = stack_pop(&operators);
		double b = stack_pop(&values);
		double a = stack_pop(&values);
		stack_push(&values, performCalculations(a, b, op));
	}

	return stack_top(&values);
}

int checkError(int error)
{
	if (error == -1) 
	{
		return 1;
	}
	return 0;
}

int checkErrorCalculations (const char* expression)
{
	char token;
	double result = 0;
	int flag = 0;
	
	while((token = *expression++) != '\0')
	{
		if(token == ' ')
		{
			continue;
		}
		if(is_digit(token))
		{
			double value = token - '0'; // Chuy?n d?i ký t? s? don thành giá tr? s? nguyên
			//expression++;
			
			while(*expression && is_digit(*expression))
			{
				value = value * 10 + (*expression++ - '0'); // Ð?c các ch? s? ti?p theo và c?p nh?t giá tr?
			}
			if (*expression && *expression == '.') {
				expression++;
				
				double decimal = 0.0;
				double decimal_factor = 0.1;
				
				while(is_digit(*expression) && *expression) {
					decimal += (*expression - '0') * decimal_factor;
					decimal_factor *= 0.1;
					expression++;
				}
				value += decimal;
			}
			if (flag == 1)
			{
				value *= -1;
				flag = 0;
			}
			
		}
		else if (token == '.')
		{
			if (*expression && !is_digit(*expression))
			{
				return 1;
			}
			double decimal = 0.0;
			double decimal_factor = 0.1;
			
			while(is_digit(*expression) && *expression) {
				decimal += (*expression - '0') * decimal_factor;
				decimal_factor *= 0.1;
				expression++;
			}
			result += decimal;
			if (flag == 1)
			{
				result *= -1;
				flag = 0;
			}
		}
		
		else if (*expression == '\0' && token != '%')
		{
			return 1;
		}
		
		else if (token == '%')
		{
			if (is_digit(*expression) || *expression == '.')
			{
				return 1;
			}
			continue;
		}
		
		else if (token == '^') {
			if (*expression && (*expression == '-' || *expression == '*' || *expression == '/'))
			{
				return 1;
			}
			continue;
		}
		else if (token == '-' || token == '+')
		{
			if (*expression && (*expression == '/' || *expression == '*'))
			{
				return 1;
			}
			continue;
		}
	}
	return 0;
}


