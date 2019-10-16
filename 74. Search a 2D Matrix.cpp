#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (!m) return false;
		int n = matrix[0].size();
		if (!n) return false;
		if (target<matrix[0][0] || target>matrix[m - 1][n - 1])
			return false;
		int l = 0, r = m - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target)
			{
				//	cout << mid << endl;
				int s = 0, e = n - 1;
				while (s <= e)
				{
					int cen = (s + e) / 2;
					//    cout << cen << endl;
					if (matrix[mid][cen] > target)
					{
						e = cen - 1;
					}
					else if (matrix[mid][cen] < target)
					{
						s = cen + 1;
					}
					else
					{
						return true;
					}
				}
				return false;
			}
			else if (matrix[mid][0] > target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return false;

	}
};