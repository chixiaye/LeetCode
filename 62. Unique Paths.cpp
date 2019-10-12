class Solution {
public:
	int uniquePaths(int m, int n) {
		long long dp[100];
		for (int i = 0; i < n; ++i)
			dp[i] = 1;
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
			{
				dp[j] += dp[j - 1];
			}
		return dp[n - 1];
	}
};
class Solution {
public:
	int uniquePaths(int m, int n) {
		// all step = m+n-2;
		//c(m-1)(m+n-2) 
		long long res = 1;
		int temp = min(m, n);
		int j = temp - 1, i = m + n - 2;
		while (i >= m + n - temp || j >= 2)
		{
			if (i >= m + n - temp)
			{
				res *= i;
				i--;
			}
			while (j >= 2 && res % j == 0)
			{
				res /= j;
				j--;
			}
		}
		return res;
	}
};