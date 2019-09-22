#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		//dp 前I个和前J个字串长度
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
					//检查是不是回文串
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

// manacher's algorithm
class Solution {
public:
	string longestPalindrome(string s) {
		//   # add
		string str = "#";
		for (int i = 0; i < s.size(); ++i)
		{
			str += "#";
			str += s[i];
		}
		str += "#";

		//vector add;
		vector<int>p(str.size(), 0);

		//  cout<<str<<endl;

			//id is the center pos mx is the right pos
		int id = 0, mx = 0, maxradius = 0, maxpos = 0;
		//start from alpha
		for (int i = 1; i < str.size(); ++i)
		{
			//three situations
			p[i] = (mx - i > 0) ? min(p[2 * id - i], mx - i) : 1;
			//p[i]=(mx-i>p[2*id-i])? min(p[2*id-i],mx-i):1;

			// beyong part
			while (p[i] + i < str.size() && i - p[i] >= 0 && str[p[i] + i] == str[i - p[i]])
			{
				p[i]++;
			}
			if (p[i] > mx - i) mx = i + p[i], id = i;
			maxradius < p[i] ? maxradius = p[i], maxpos = i : maxradius;
		}
		return s.substr((maxpos - maxradius) / 2, maxradius - 1);
	}
};