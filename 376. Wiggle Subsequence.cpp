#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < nums.size() ; ++i)
		{
			if (nums[i] != res[res.size() - 1])
			{
				if (res.size() == 1) res.push_back(nums[i]);
				else if ((res[res.size() - 1] - res[res.size() - 2]) * (nums[i] - res[res.size() - 1]) < 0)
				{
						res.push_back(nums[i]); 
				}
			}
		}
		return res.size();
	}
};