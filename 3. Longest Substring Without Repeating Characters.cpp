#include<string>
#include<set>
#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int a[128], res = 0, len = s.size(), cur = 0;
		memset(a, -1, sizeof(a));
		for (int i = 0; i < len; ++i)
		{
			if (a[s[i]] == -1)
			{
				a[s[i]] = i;
				cur++;
			}
			else
			{
				res = max(res, cur);
				for (int j = 32; j < 128; ++j)
				{
					if (a[s[i]] > a[j] && a[j] >= 0)
					{
						cur--;
						a[j] = -1;
					}
				}
				a[s[i]] = i;
			}
		}
		return  max(res, cur);
	}
};

//维护一个滑动的序列
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int a[128], res = 0, len = s.length(),  start = -1;
		memset(a, -1, sizeof(a)); 
		for (int i = 0; i < len; ++i)
		{
			//维护的是前面的部分 ABCABC
			if (a[s[i]] > start)
			{
				//从上一个重复出现的地方开始
				start = a[s[i]];
			} 
			//更新当前
			a[s[i]] = i;
			//当前减去上一个出现的位置
			res = max(res, i - start);
		}
		return  res;
	}
};