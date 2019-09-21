#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		//dp ǰI����ǰJ���ִ�����
		std::vector<std::vector<int>> dp(
			len, std::vector<int>(len, 0));
		std::vector<std::vector<bool>> p(
			len, std::vector<bool>(len, true));
		int maxlen = 1;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == s[len - 1])
			{
				dp[i][0] = 1;
			}
			if (s[0] == s[len - i - 1])
			{
				dp[0][i] = 1;
			}
		}
		 
		int left = 0;//,right=0 ;
		for (int i = 1; i < len; ++i)
		{
			for (int j = 1	; j < len; ++j)
			{
				dp[i][j] = (s[len - 1 - j] == s[i]) ? dp[i - 1][j - 1] + 1 : 0;
				if (maxlen < dp[i][j]&&check(s,i,dp[i][j]))
				{
					//����ǲ��ǻ��Ĵ�
					maxlen = dp[i][j];
					left = i;//right=len-j;
				}
			}
		}
		//printf("%d   %d\n", left, maxlen);

		string res = s.substr(left - maxlen + 1, maxlen);
		return res;
	}
	bool check(string s, int left, int maxlen)
	{
		string temp= s.substr(left - maxlen + 1, maxlen);
		for (int i = 0; i < temp.length(); ++i)
		{
			if (temp[i] != temp[temp.length() - 1 - i])
				return false;
		}
		return true;
	}
};

//Manacher's Algorithm
class Solution {
public:
	string longestPalindrome(string s) {
	 
	}
	 
};