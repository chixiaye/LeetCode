#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
//每次更新能到达的最大点
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int  reach = 0;
		for ( int i=0; i < n && i <= reach; ++i)
		{
			reach = max(i + nums[i], reach);
			if (reach >= n-1)
			{
				return true;
			}
		}
		return false;
	} 
};
 
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		vector<bool> vis(len, false);
		vis[0] = true;
		for (int i = 1; i < len; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
				if (vis[j] == true && j + nums[j] >= i)
				{
					vis[i] = true;
					break;
				}
		}

		return vis[len - 1];
	}
};