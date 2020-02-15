#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> splitIntoFibonacci(string S) {
		vector<int> res;
		if (dfs(S, 1, res))
		{
			return res;
		}
		res.clear();
		return res;
	}
	bool dfs(string S, int len, vector<int>& res)
	{
		if (S == "")
			return true;
		for (int i = (res.size() >= 2) ? len : 1; i <= S.length() && i < 13; ++i)
		{
			string temp = S.substr(0, i);
			if (i >= 2 && temp[0] == '0' || temp == "")
			{
				return false;
			}
			long long v = atol(temp.c_str());
			if (v > INT_MAX)
				break;
			int val = v;
			if (res.size() < 2 || val - res[res.size() - 1] == res[res.size() - 2])
			{
				res.push_back(val);
				string str = S.substr(temp.length());
				//for(int k=0;k<res.size();++k)
				//    cout<<res[k]<<',';
			   // cout<<endl;
				bool ans = dfs(str, i, res);
				if (res.size() > 2 && ans)
					return true;
				res.pop_back();
			}
		}
		return false;
	}
};