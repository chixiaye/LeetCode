#include<vector>
#include<string>
#include<algorithm>
using namespace std; 
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};