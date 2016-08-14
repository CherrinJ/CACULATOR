#include "myString.h"
#include "myMath.h"

string cTostring(char ch)
{
	char* _ch = &ch;
	return (string)_ch;
}

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