#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

#include "myMath.h"
#include "myStack.h"
#include "calFile.h"
#include "myString.h"

using namespace std;

#define ERROR 0xffffffff;

int main()
{
	//add a file contain expression that need to calculate
	//the file got from calculator/output/data/
	CalFile file("input.txt");
	string t_str = file.read();

	cout<<t_str<<endl;

	MyStack<string> str_stack;
	double sum = 0.0;
	int bracketCount = 0;

	int i = 0;
	while(t_str[i] != '\0')
	{
		if(t_str[i] == '(')
			{
					++bracketCount;
			}
			else if (t_str[i] == ')')
			{
				--bracketCount;
			}
			else
			{
				str_stack.push(cTostring(t_str[i]));
			}
		++i;
	}

	if (bracketCount != 0)
	{
		cout<<"what inputed format is wrong1 !"<<endl;
		return ERROR;
	}

	//calculate expression
	sum = calculator(str_stack);

	cout << "the result is :"<<sum <<endl;
	return 0;
}

