#include <iostream>
#include <string>
#include <climits>

using namespace std;

int RomanChangeToInt(char ch)
{
	int num = 0;
	switch(ch)
	{
	case 'I':
		num = 1; break;
	case 'V':
		num = 5; break;
	case 'X':
		num = 10; break;
	case 'L':
		num = 50; break;
	case 'C':
		num = 100; break;
	case 'D':
		num = 500; break;
	case 'M':
		num = 1000; break;
	default:
		num = -1; break;
	}
	return num;
}

int romanToInt(string s) 
{
	int sum = 0;
	for(int pre = INT_MAX, cur = 0; cur != s.size(); ++cur)
	{
		int num = RomanChangeToInt(s[cur]);
		if(pre < num)
		{
			sum -= 2 * pre;
		}
		sum += num;
		pre = num;
	}
	return sum;
}

int main()
{
	string s = "DCXXI";
	cout << romanToInt(s) << endl;
	system("pause");
	return 0;
}