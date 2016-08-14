#pragma once
#ifndef __MYMATH__H__
#define __MYMATH__H__

#include <string>
#include <stdio.h>

#include "myStack.h"

#define ERROR 0xffffffff;

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

template <class T>
inline double countByOperator(T a_str, double a_x, double a_y)
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

template <class T>
bool IsBracket(T a_str)
{
	if (a_str == "(" || a_str == ")")
		return true;
	return false;
}

template <class T>
bool IsOperators(T a_str)
{
	if (a_str == "*" || a_str == "/" || a_str == "+" || a_str == "-")
		return true;
	return false;
}



template <class T>
T numConvertToStr(double a_x)
{
	char t_ch = (a_x + 48);
	T str = t_ch;
	return str;
}

template <class T>
double calculator(MyStack<T>& a_stack)
{
	MyStack<T> num_stack;
	bool isFormatWrong = false;
	bool isFirst = true;
	double result = 0.0;

	while (!a_stack.IsEmpty())
	{
 		T str = a_stack.pop();
		if(str != "*" && str != "/" && str != "+" && str != "-")
		{
			num_stack.push(str);
		}
		else if (str == "*" || str == "/" || str == "+" || str == "-")
		{
			if(num_stack.IsEmpty())
			{
				cout<< "what inputed string format is wrong2!"<<endl;
				isFormatWrong = true;
				break;
			}
			if (isFirst)
			{
				int a_agr = strConvertToNum(num_stack.pop());
				int b_agr = strConvertToNum(num_stack.pop());
				result = countByOperator(str, a_agr, b_agr);
				isFirst = false;
			}
			else
			{
				result = countByOperator(str, result,strConvertToNum(num_stack.pop()));
			}
		}
		else
		{
			cout<< "wrong charactor %s !"<<str<<endl;
			isFormatWrong = true;
			break;
		}
	}

	if (!num_stack.IsEmpty())
	{
		cout<< "string format inputed is wrong!"<<endl;
		isFormatWrong = true;
	}

	if(isFormatWrong)
	{
		return ERROR;
	}
	return result;
}


#endif //#ifndef __MYMATH__H__