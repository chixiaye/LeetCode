#include<vector>
#include<map>
#include<iostream>
using namespace std; 
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int na(0), nb(0);//00 01 00
		for (auto i : nums)
		{
			na = (i ^ na) & ~nb; //0^x = x 1^x = ~x
			nb = (i ^ nb) & ~na;// ~起到清除作用
			//cout << na << '\t' << nb << endl;
		}
		//统计每个bit上1出现的次数 na记录出现奇数次 nb出现偶数次    01 01 11 01  : 0-1-2-0  add
		return na;
	}
};
/*
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int>m;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (m.find(nums[i]) == m.end())
				m.insert(pair<int, int>(nums[i], i));
			else 
				m[nums[i]]++;
		}
		for (auto s : m)
		{
			if (s.second == 3)
				return s.first;
		}
	}
};
*/