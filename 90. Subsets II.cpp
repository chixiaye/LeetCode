#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>>res;
		vector<int>t;
		res.push_back(t);
		if (!n) return res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i)
		{
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			vector<int>temp(1, nums[i]);
			f(res, temp, i + 1, n, nums);
		}
		return res;
	}
	void f(vector<vector<int>>& res, vector<int>& temp, int cur, int n, vector<int> nums)
	{
		if (cur >= n)
		{
			res.push_back(temp);
			return;
		}
		else
		{
			
			for (int i = cur; i < n; ++i)
			{
				if (i>cur&&nums[i - 1] == nums[i])
					continue;
				temp.push_back(nums[i]);
				f(res, temp, i + 1, n, nums);
				temp.pop_back();
				if (i == cur)
				{
					int j = 0;
					while (i + j < n && nums[i + j] == nums[i]) j++;
					f(res, temp, i + j, n, nums);
				}
			}
			return;
		}
	}
};
//更简单的写法 选的元素要么不重复要么重复，不重复的时候直接加到已有的子集合中作为新的子集，
//重复的则有一个count判断，在第一个数字A出现时候都加了一个A，接下来只会对已经有一个A的部分继续加
//复杂度为O(n^2)
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>>res;
		vector<int>t;
		res.push_back(t);
		if (!n) return res;
		sort(nums.begin(), nums.end());
		int count=0;
		for (int i = 0; i < n;++i )
		{
			if (i > 0 && nums[i] != nums[i - 1]) count = 0;
			int reslen = res.size();
			for (int k = reslen; count < k; ++count)
			{
				vector<int> temp = res[count];
				temp.push_back(nums[i]);
				res.push_back(temp);
			} 
		}
		return res;
	}
};