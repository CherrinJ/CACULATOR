#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

#include "myMath.h"
#include "myStack.h"

using namespace std;

#define ERROR 0xffffffff;

int main()
{

	string t_str;
	MyStack<string> str_stack;
	double sum = 0.0;
	int bracketCount = 0;

	string str = numConvertToStr(210.0);

	cout<<"input what you want to count and input '#' at the end:"<<endl;
	while(cin >> t_str)
	{
		if (t_str == "#")
			break;

		else
		{
			if(t_str == "(")
			{
					++bracketCount;
			}
			else if (t_str == ")")
			{
				--bracketCount;
			}
			else
			{
				str_stack.push(t_str);
			}
		}
	}

	if (bracketCount != 0)
	{
		cout<<"what inputed format is wrong1 !"<<endl;
		return ERROR;
	}

	sum = calculator(str_stack);

	cout << "the result is :"<<sum <<endl;
	return 0;
}

