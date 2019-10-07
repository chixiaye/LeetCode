#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std; 
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//swap the first descend sequence
		int len = nums.size();
		int k = 0;
		//first step find the < one
		for (int i = len - 2; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])// handle i+1~len-1
			{
				k = i + 1;
				break;
			}
		}
		int temp = k - 1;//=false;
		for (int j = (len - 1 + k) / 2; j >= k; --j)
		{
			swap(nums[j], nums[len - 1 - (j - k)]);
			//attention = ensure the temp can move forward
			if (k > 0 && nums[j] > nums[k - 1] && (temp == k - 1 || nums[j] <= nums[temp]))
			{
				temp = j;
			}
			else if (k > 0 && nums[len - 1 - j + k] > nums[k - 1] && (nums[len - 1 - j + k] < nums[temp] || temp == k - 1))
			{
				temp = len - 1 - j + k;
			}
		}
		if (k > 0) swap(nums[temp], nums[k - 1]);
	}
};