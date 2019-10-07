#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans(2, -1);
		int len = nums.size();
		if (len == 0) return ans;
		//find the lowlist boundary
		int l = 0, r = len;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] >= target)
			{
				r = mid;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
		}
		if (l >= 0 && l < len && nums[l] == target)
			ans[0] = l;
		//find the highlist boundary
		l = 0, r = len;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (nums[mid] > target)
			{
				r = mid;
			}
			else if (nums[mid] <= target)
			{
				l = mid + 1;
			}
		}
		if (l - 1 >= 0 && l - 1 < len && nums[l - 1] == target)
			ans[1] = l - 1;
		return ans;
	}
};