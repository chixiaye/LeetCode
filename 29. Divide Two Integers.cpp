#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
		int quotient = 0;
		if (dividend == INT_MIN)
		{
			if (divisor == -1) return INT_MAX;
			else if (divisor == 1) return INT_MIN;
			else if (divisor == INT_MIN) return 1;
			dividend += fabs(divisor);
			quotient++;
		}
		else if (divisor == INT_MIN) return 0;
		unsigned int a = abs(dividend);
		unsigned int b = abs(divisor);

		if (a < b) return sign * quotient;
		else if (a == b) return sign * (1 + quotient);
		else
		{
			while (a >= b)
			{
				int m = 1, temp = b;
				while (temp << 1 < a)
				{
					temp <<= 1;
					m <<= 1;
				}
				quotient += m;
				a -= temp;
			}
		}
		return quotient * sign;
	}
};