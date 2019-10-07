#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector< vector<int> > res;
		vector<int> temp;
		f(target, candidates, res, temp, 0);
		return res;
	}
	void f(int target, vector<int>  candidates, vector< vector<int> >& res, vector<int>& temp, int k)
	{
		if (target == 0)
		{
			res.push_back(temp);
		}
		else
		{
			int m = temp.size();
			int n = candidates.size();
			for (int i = k; i < n; ++i)
			{
				if (candidates[i] <= target)
				{
					temp.push_back(candidates[i]);
					f(target - candidates[i], candidates, res, temp, i);
					temp.erase(temp.begin() + m);
				}
			}

		}
	}
};