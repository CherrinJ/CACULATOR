#include "myMath.h"

#define ERROR 0xffffffff;

double strConvertToNum(string a_str)
{
	double result = 0.0;
	int l = a_str.length();
	int i = 0;
	int point_flag = l;
	int poit_count = 0;
	for(int j = 0 ; j <= l; j++)
	{
		if (a_str[j] == '.')
		{
			point_flag = j;
			break;
		}
	}
	while (i < l)
	{
		if(i < point_flag)
		{
			int c_int = charConvertToInt(a_str[i]);
			int p_l = point_flag - i - 1;
			result += c_int * power(p_l, 10);
			
		}
		else
		{
			if(a_str[i] == '.')
			{
				if(i != point_flag)
				{
					cout<<"number of format is wrong!"<<endl;
				}
			}
			else{
				double c_decimal = charConvertToInt(a_str[i]);
				++poit_count;
				result += c_decimal * power(poit_count, 0.1);
			}
		}
		++i;
	}
	return result;
}

string numConvertToStr(double a_x)
{
	char t_ch = (a_x + 48);
	string str = "\0";
	str = t_ch;
	return str;
}

double calculator(MyStack<string>& a_stack)
{
	MyStack<string> num_stack;
	bool isFormatWrong = false;
	bool isFirst = true;
	double result = 0.0;

	while (!a_stack.IsEmpty())
	{
 		string str = a_stack.pop();
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

double strConvertToDouble(string a_str)
{
	double result = 0.0;
	int poit_count = 0;
	int point_flag;
	int l = a_str.length();

	for(int j = 0 ; j <= l; j++)
	{
		if (a_str[j] == '.')
		{
			point_flag = j;
			break;
		}
	}

	int i = 0;
	while (i < l)
	{
		if(i < point_flag)
		{
			int c_int = charConvertToInt(a_str[i]);
			int p_l = point_flag - i - 1;
			result += c_int * power(p_l, 10);
		}
		else if (i > point_flag)
		{
			int c_decimal = charConvertToInt(a_str[i]);
			++poit_count;
			result += c_decimal * power(poit_count, 0.1);
		}
		++i;
	}
	return result;
}