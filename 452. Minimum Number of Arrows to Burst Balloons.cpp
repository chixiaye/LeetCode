#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool static cmp(const vector<int>& a, const  vector<int>& b)
	{
		return a[1] < b[1];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0) return 0;
		sort(points.begin(), points.end(), cmp);
		int res = 1;
		int temp = points[0][1];
		for (int i = 1; i < points.size(); ++i)
		{
			if (points[i][0] > temp)
			{
				res++;
				temp = points[i][1];
			}
		}
		return res;
	}
};