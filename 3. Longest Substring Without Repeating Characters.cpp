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

//ά��һ������������
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int a[128], res = 0, len = s.length(),  start = -1;
		memset(a, -1, sizeof(a)); 
		for (int i = 0; i < len; ++i)
		{
			//ά������ǰ��Ĳ��� ABCABC
			if (a[s[i]] > start)
			{
				//����һ���ظ����ֵĵط���ʼ
				start = a[s[i]];
			} 
			//���µ�ǰ
			a[s[i]] = i;
			//��ǰ��ȥ��һ�����ֵ�λ��
			res = max(res, i - start);
		}
		return  res;
	}
};