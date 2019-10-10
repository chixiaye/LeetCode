#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	static bool comp(const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int len = intervals.size();
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end(), comp);
		if (len) res.push_back(intervals[0]);
		else return res;
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][0] <= res[res.size() - 1][1])
			{
				res[res.size() - 1][1] = max(intervals[i][1], res[res.size() - 1][1]);
			}
			else
			{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};