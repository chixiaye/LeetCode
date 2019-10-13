#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid.size();
		if (!n) return 0;
		vector<int> dp(n, 0);
		dp[0] = grid[0][0];
		for (int i = 1; i < n; ++i)
			dp[i] = dp[i - 1] + grid[0][i];
		for (int i = 1; i < m; ++i)
		{
			dp[0] += grid[i][0];
			for (int j = 1; j < n; ++j)
			{
				dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
			}
		}
		return dp[n - 1];
	}
};