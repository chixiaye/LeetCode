#include<vector>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m)
			return;
		int n = matrix[0].size();
		if (!n)
			return;
		int last_row = -1;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					last_row = -1;
					break;
				}
			}
		if (last_row == -1)
			return;
		for (int i = 0; i < last_row; ++i)
		{
			bool zero_row = false;
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[last_row][j] = 0;
					zero_row = true;
				}
			}
			if (zero_row)
			{
				for (int k = 0; k < n; ++k)
					matrix[i][k] = 0;
			}
		}

		for (int j = 0; j < n; ++j)
		{
			if (matrix[last_row][j] == 0)
			{
				matrix[last_row][j] = 0;
				for (int k = 0; k < m; ++k)
					matrix[k][j] = 0;
			}
		}
		return;
	}
};