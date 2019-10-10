#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int step[4][2] = { 0,1,1,0,0,-1,-1,0 };
		vector<vector<int>> res;
		if (!n) return res;
		for (int i = 1; i <= n; ++i)
		{
			vector<int> temp(n, 0);
			res.push_back(temp);
		}
		int x = 0, y = 0, i = 1;
		res[0][0] = 1;
		while (i <= n * n) {
			for (int j = 0; j < 4; ++j)
			{
				while (i <= n * n && x + step[j][0] >= 0 && x + step[j][0] < n && y + step[j][1] < n && y + step[j][1] >= 0)
				{ 
					if (res[x + step[j][0]][y + step[j][1]])
						break;
					x += step[j][0];
					y += step[j][1];
					res[x][y] = i++;
				}
			}
		}
		return res;
	}
};