#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = 0;
		vector<vector<int>> res;
		while (n < (1 << nums.size()))
		{
			int p = n;
			int i = 0;
			vector<int> temp;
			do
			{
				if (p & 1)
					temp.push_back(nums[i]);
				i++;
				p >>= 1;
			} while (p > 0);
			res.push_back(temp);
			n++;
		}
		return res;
	}
};