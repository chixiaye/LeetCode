#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.length(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (!dp[j]) continue;
				string temp = s.substr(j, i - j);
				if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.length()];

	}
};