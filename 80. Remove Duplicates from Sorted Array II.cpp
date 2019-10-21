#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int res = nums.size();
		if (res < 3) return res;
		for (int i = 2; i < res;)
		{
			while (i < res && res>2 && nums[i] == nums[i - 2] && nums[i] == nums[i - 1])
			{
				res--;
				nums.erase(nums.begin() + i);
			}
			i++;
		}
		return res;
	}
};