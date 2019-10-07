#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>> res;
class Solution {
public:
	void dummy(vector<int>& num, int i, int j) {
		if (i == j)
			res.push_back(num);
		for (int start = i; start <= j; start++) {
			swap(num[i], num[start]);
			dummy(num, i + 1, j);
			swap(num[i], num[start]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		int n = nums.size();
		res.clear();
		dummy(nums, 0, n - 1);
		return res;
	}
};