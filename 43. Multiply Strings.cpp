#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2)
	{
		int len1 = num1.size(), len2 = num2.size();
		string sum(len1 + len2, '0');
		for (int i = len1 - 1; 0 <= i; --i)
		{
			int carry = 0;
			for (int j = len2 - 1; 0 <= j; --j)
			{
				//key i+j+1=  len1+len2-1-(  (len1-1-i)+(len2-1-j) ) 
				int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			sum[i] += carry;
		}
		for (int i = 0; i < len1 + len2; i++) {
			if (sum[i] != '0') {
				return sum.substr(i);
			}
		}
		return "0";
	}
};
