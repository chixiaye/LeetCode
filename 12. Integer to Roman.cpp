#include<string>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		int base = 10000;
		string res;
		while (base != 1)
		{
			int v = num % base - num % (base / 10);
			base /= 10;
			int temp;
			if (v >= 1000)
			{
				temp = v / 1000;
				while (temp--)
				{
					res += "M";
				}
			}
			else if (v >= 500)
			{
				temp = v / 100 - 5;
				if (v < 900)
				{
					res += "D";
					while (temp--)
					{
						res += "C";
					}
				}
				else
				{
					res += "CM";
				}
			}
			else if (v >= 100)
			{
				temp = v / 100;
				if (v < 400)
				{
					while (temp--)
					{
						res += "C";
					}
				}
				else
				{
					res += "CD";
				}
			}
			else if (v >= 50)
			{
				temp = v / 10 - 5;
				if (v < 90)
				{
					res += "L";
					while (temp--)
					{
						res += "X";
					}
				}
				else
				{
					res += "XC";
				}
			}
			else if (v >= 10)
			{
				temp = v / 10;
				if (v < 40)
				{
					while (temp--)
					{
						res += "X";
					}
				}
				else
				{
					res += "XL";
				}
			}
			else if (v >= 5)
			{
				temp = v - 5;
				if (v < 9)
				{
					res += "V";
					while (temp--)
					{
						res += "I";
					}
				}
				else
				{
					res += "IX";
				}
			}
			else if (v >= 0)
			{
				temp = v;
				if (v < 4)
				{
					while (temp--)
					{
						res += "I";
					}
				}
				else
				{
					res += "IV";
				}
			}
		}
		return res;
	}
};