#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>res;
		if (n < 1 || n < k)
			return res;
		vector<int> temp;
		f(res, 1, n, k, temp);
		return res;
	}
	void f(vector<vector<int>>& res, int s, int e, int rest, vector<int>& temp)
	{
		if (rest)
		{
			for (int i = s; i <= e-rest+1; ++i)
			{
				temp.push_back(i);
				f(res, i + 1, e, rest - 1, temp);
				temp.pop_back();
			}
		}
		else
		{
			res.push_back(temp);
			return;
		}
	}
};