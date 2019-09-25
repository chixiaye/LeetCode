#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		//     nums.erase(unique(nums.begin(),nums.end()),nums.end());
			 //unuque()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的
			 //迭代器 ，在用erase函数擦除从这个元素到最后元素的所有元素
		int len = nums.size();
		if (len < 3)
			return res;
		int i = len - 1;
		while (i >= 2)
		{
			if (nums[i] < 0) break;
			int front = 0;
			int mid = i - 1;
			while (mid >= 0 && front < mid)
			{
				int v = nums[i] + nums[front] + nums[mid];
				if (!v)
				{
					vector<int> temp = { nums[front],nums[mid],nums[i] };
					res.push_back(temp);
					//left or right can regard it as a kind of balance
					do {
						mid--;
					} while (front < mid && temp[1] == nums[mid]);
				}
				else if (v > 0)
				{
					do {
						mid--;
					} while (front < mid && nums[mid + 1] == nums[mid]);
				}
				else
				{
					do {
						++front;
					} while (front < mid && nums[front - 1] == nums[front]);
				}
			}
			do {
				--i;
			} while (i >= 0 && nums[i + 1] == nums[i]);
		}
		return res;
	}
};
/*
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		//     nums.erase(unique(nums.begin(),nums.end()),nums.end());
			 //unuque()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的
			 //迭代器 ，在用erase函数擦除从这个元素到最后元素的所有元素
		int len = nums.size();
		if (len < 3)
			return res;
		int i = len - 1;
		while (i >= 2)
		{
			if (nums[i] < 0) break;
			int front = 0;
			int mid = i - 1;
			while (mid >= 0 && front < mid)
			{
				int v = nums[i] + nums[front] + nums[mid];
				if (!v)
				{
					vector<int> temp = { nums[front],nums[mid],nums[i] };
					res.push_back(temp);
					//left or right can regard it as a kind of balance
					do {
						mid--;
					} while (front < mid && temp[1] == nums[mid]);
				}
				else if (v > 0)
				{
					do {
						mid--;
					} while (front < mid && nums[mid + 1] == nums[mid]);
				}
				else
				{
					do {
						++front;
					} while (front < mid && nums[front - 1] == nums[front]);
				}
			}
			do {
				--i;
			} while (i >= 0 && nums[i + 1] == nums[i]);
		}
		return res;
	}
};
*/