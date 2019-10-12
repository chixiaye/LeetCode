#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (!m)
			return 0;
		int n = obstacleGrid[0].size();
		if (!n)
			return 0;
		vector<long long> dp(n, 0);
		dp[0] = !obstacleGrid[0][0];
		for (int i = 0; i < m; ++i)
		{
			if (obstacleGrid[i][0])
				dp[0] = 0;
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j])
					dp[j] = 0;
				else
					dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};