#pragma once
#ifndef __MYMATH__H__
#define __MYMATH__H__

#include <string>
#include <stdio.h>

#include "myStack.h"

using namespace std;

inline int charConvertToInt(char a_c)
{
	return ((int)a_c - 48);
}

inline char intConvertToChar(int a_x)
{
	return (a_x + 48);
}

inline double power(int a_x ,double a_y)
{
	double result = 1.0;
	while (a_x > 0)
	{
		result *= a_y;
		--a_x;
	}
	return result;
}

inline double countByOperator(string a_str, double a_x, double a_y)
{
	double result = 0.0;

	if (a_str == "*")
	{
		result = a_x * a_y;
	}
	else if (a_str == "/")
	{
		result = a_x / a_y;
	}
	else if (a_str == "+")
	{
		result = a_x + a_y;
	}
	else if (a_str == "-")
	{
		result = a_x - a_y;
	}
	else
	{
		cout << " wrong operator"<<endl;
	}	
	return result;
}

inline bool IsBracket(string a_str)
{
	if (a_str == "(" || a_str == ")")
		return true;
	return false;
}

inline bool IsOperators(string a_str)
{
	if (a_str == "*" || a_str == "/" || a_str == "+" || a_str == "-")
		return true;
	return false;
}

double strConvertToNum(string a_str);
double strConvertToDouble(string a_str);
string numConvertToStr(double a_x);

double calculator(MyStack<string>& a_stack);

#endif //#ifndef __MYMATH__H__