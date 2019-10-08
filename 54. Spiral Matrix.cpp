#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size()-1;
		if (m==-1) return res;
		int n = matrix[0].size()-1;
		int x = 0, y = 0;
		while (x <= m && y <= n)
		{
			for (int j = y; j <=  n; ++j)
				res.push_back(matrix[x][j]);
			for (int j = x+1; j <=  m; ++j)
				res.push_back(matrix[j][n]);
			if (x<m&&y<n)
			{
				for (int j = n-1; j > y; --j)
					res.push_back(matrix[m][j]);
				for (int j = m; j > x; --j)
					res.push_back(matrix[j][y]);
			}
			x++, y++;
			m--, n--;
		}
		return res;
	}
};