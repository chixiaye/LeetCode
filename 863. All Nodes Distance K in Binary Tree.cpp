#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool static cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	}
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>> res;
		vector<vector<int>> v;
		for (int i = 0; i < groupSizes.size(); ++i)
		{
			vector<int> temp;
			temp.push_back(i);
			temp.push_back(groupSizes[i]);
			v.push_back(temp);
		}
		sort(v.begin(), v.end(), cmp);
		int val = 0;
		for (int i = 0; i < v.size();)
		{
			val = v[i][1];
			vector<int>t;
			int j = i;
			for (; val > 0 && j < v.size(); ++j)
			{
				t.push_back(v[j][0]);
				val--;
			}
			res.push_back(t);
			i = j;
		}
		return res;
	}
};