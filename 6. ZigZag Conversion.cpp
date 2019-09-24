#include<iostream>
#include<string>
#include<vector>
using namespace std;
//题解： 走路 往下往上走 最后一行行连起来填入 
class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		string res;
		if (numRows == 1)
			return s;
		if (numRows == 2)
		{
			for (int i = 0; 2 * i < len; ++i)
			{
				res += s[i * 2];
			}
			for (int i = 1; 2 * i - 1 < len; ++i)
			{
				res += s[i * 2 - 1];
			}
			return res;
		}
		int grouplen = numRows * 2 - 2;
		int group = len % (grouplen) == 0 ? len / (numRows * 2 - 2) : len / (numRows * 2 - 2) + 1;
		int temp = len % (grouplen) == 0 ? 0 : grouplen - len % (grouplen);
		//printf("%d %d %d\n", group, grouplen, temp);
		while (temp--) s += "#";
		for (int i = 0; i < numRows; ++i)
		{
			for (int j = 0; j < group; ++j)
			{
				int v = j * grouplen + i;
				if (s[v] != '#')
					res += s[v];
				if (i != 0 && i != numRows - 1)
				{
					if (s[v - i + grouplen - i] != '#')
						res += s[v - i + grouplen - i];
				}
			}
			//		cout << res << endl;
		}
		return res;
	}
};