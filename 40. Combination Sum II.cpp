#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector< vector<int> > res;
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		f(target, candidates, temp, 0);
		return res;
	}
	void f(int target, vector<int>  candidates, vector<int>& temp, int k)
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
				if (i > k && candidates[i] == candidates[i - 1])
					continue;
				if (candidates[i] <= target)
				{
					temp.push_back(candidates[i]);
					f(target - candidates[i], candidates, temp, i + 1);
					temp.erase(temp.begin() + m);
				}
			}
		}
	}
};