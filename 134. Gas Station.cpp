#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int cur = 0;
		int ans = 0, total = 0;
		for (int i = 0; i < cost.size(); ++i)
		{
			cur += gas[i] - cost[i];
			if (cur < 0)
			{
				total += cur;//+gas[i]-cost[i];
				cur = 0;
				ans = i + 1;
			}
		}
		return (total + cur >= 0) ? ans : -1;
	}
};