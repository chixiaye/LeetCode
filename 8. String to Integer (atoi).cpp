#include<string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int len = str.length();
		int sign = 0;//true is +1 false is -1
		int res = 0;
		string s = "";
		for (int i = 0; i < len; ++i)
		{
			if (sign == 0 && str[i] == ' ')
				continue;
			else if (sign == 0 && str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9'))
			{
				return 0;
			}
			else if (sign == 0 && (str[i] == '+' || str[i] == '-'))
			{
				sign = (str[i] == '+') ? 1 : -1;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				sign != 0 ? sign : sign = 1;
				if (s.length() || str[i] != '0')
					s += str[i];
			}
			else if (sign != 0 && !(str[i] >= '0' && str[i] <= '9'))
			{
				break;
			}

		}
		int sl = s.length();
		if (sign == 1 && (sl > 10 || sl == 10 && "2147483647" <= s))
			return INT_MAX;
		else if (sign == -1 && (sl > 10 || sl == 10 && "2147483648" <= s))
			return INT_MIN;
		int  base = 1;
		if (sl <= 0) return 0;
		res = s[sl - 1] - '0';
		for (int i = sl - 2; i >= 0; --i)
		{
			base *= 10;
			int temp = base * (s[i] - '0');
			res += temp;
			//    printf("%d\n",res);
		}
		//   printf("%d %d\n",res,sign);
		return sign * res;
	}
};