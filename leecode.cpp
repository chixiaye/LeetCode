// leecode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include<vector>
#include<algorithom>
#include <iostream>
using namespace std;
int main()
{  
	return 0;
}

class Solution {
public:
	int maxArea(vector<int>& height) { 
		int len = height.size();
		int res = 0;
		for (int i = 0; i < len; ++i) qwe
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