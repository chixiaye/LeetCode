#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		double res = 1;
		int sign = 1;
		if (n == 0) return 1;
		else if (n < 0)
		{
			x = 1 / x;
			if (n != INT_MIN)
				n = -n;
			else
			{
				n = INT_MAX;
				sign = x;
			}
		}
		while (n)
		{
			if (n & 1)
			{
				res *= x;
			}
			n >>= 1;
			x *= x;
		}
		return res * sign;
	}
};