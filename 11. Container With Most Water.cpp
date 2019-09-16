// leecode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
int main()
{
	return 0;
}

//暴力搜索法+基本减枝
class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int res = 0;
		for (int i = 0; i < len; ++i)
		{
			for (int j = len - 1; j >= i + 1; --j)
			{
				if (height[i] <= height[j])
				{
					res = max(res, (j - i) * height[i]);
					break;
				}
				else
				{
					res = max(res, (j - i) * height[j]);
				}
			}
		}
		return res;
	}
};

//双指针法 
class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int res = 0;
		int left=0 , right = len-1;
		while (left < right) 
		{
			res = max(res, (right - left) *min( height[right],height[left]));
			if (height[left] <  height[right])
			{ 
				do
				{
					left++;
				} while (left < right&& height[left - 1] >= height[left]); 
			}
			else
			{ 
				do
				{
					right--;
				} while (left < right && height[right+1] >= height[right]);
			}
		} 
		return res;
	}
};	