#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std; 
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		int len = nums.size();
		sort(nums.begin(), nums.end());
		int res = nums[len - 3] + nums[len - 2] + nums[len - 1];
		if (res == target) return res;
		for (int i = 2; i < len; ++i)
		{
			int fear = 0;
			int back = i - 1;
			while (fear < back && back>0)
			{
				int v = nums[fear] + nums[back] + nums[i];
				if (target == v)
					return v;
				else if (v < target)
				{
					fear++;
				}
				else
				{
					back--;
				}
				if (abs(v - target) < abs(res - target))
					res = v;
			}
		}
		return res;
	}
};