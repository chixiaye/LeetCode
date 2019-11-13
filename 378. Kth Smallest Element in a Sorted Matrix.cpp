#include<vector>
using namespace std;
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int cur = 0;
		for (int i = 1; i < matrix.size(); ++i)
		{
			int t = 0;
			if (matrix[i][0] >= matrix[i - 1][matrix[i - 1].size() - 1])
			{
				t = matrix[i - 1].size();
			}
			else 
			{
				t=1+f(matrix[i - 1], matrix[i][0]);

			}
			if (cur + t < k)
				cur += t;
			else
				return matrix[i - 1][k - cur - 1];

		}
	}
	int f(vector<int> matrix, int v)
	{
		return 0;
	}
};