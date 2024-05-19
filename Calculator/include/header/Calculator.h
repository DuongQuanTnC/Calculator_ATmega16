/*
 * Calculator.h
 *
 * Created: 28/04/2024 15:32:32
 *  Author: duong
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stdlib.h>
#include <math.h>
#include "stdint.h"

#define STACK_SIZE 30

int precedence(char op);
int checkDivideByZero(double a, double b, char op);
double performCalculations (double a, double b, char op);
int checkErrorCalculations (const char* expression);
double evaluate_expression(const char* expression);
float sqrt_num(float x);
int checkError(double num);
double power(int64_t b, int64_t e);

#endif /* CALCULATOR_H_ */