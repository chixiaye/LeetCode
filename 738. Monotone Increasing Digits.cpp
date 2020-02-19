#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		vector<int> v;
		while (N)
		{
			v.push_back(N - N / 10 * 10);
			N /= 10;
		}
		vector<int> res;
		res.push_back(v[v.size() - 1]);
		for (int i = v.size() - 2; i >= 0; --i)
		{
			if (v[i] >= v[i + 1])
			{
				res.push_back(v[i]);
			}
			else
			{
				res.push_back(-1);
				//res[j]--;
				for (int j = res.size() - 1; j > 0; --j)
				{
					if (res[j] < res[j - 1])
						res[j] = 9, res[j - 1]--;
				}
				for (; res.size() < v.size();)
					res.push_back(9);
				break;
			}
		}
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << endl;
		}
		int ans = 0;
		for (int i = res.size() - 1, val = 1; i >= 0; --i)
		{
			ans += res[i] * val;
			val *= 10;
		}

		return ans;
	}
};