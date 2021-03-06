#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board)
	{
		int m = board.size();
		if (!m) return;
		int n = board[0].size();
		if (!n) return; 
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 'X'||  board[i][j]==1)
					continue;
				else if (i == 0 || i + 1 == m || j == 0 || j + 1 == n)
				{
					dfs(board , i, j, m, n);
				}
			}
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				board[i][j] = (board[i][j]==1) ? 'O' : 'X';
			}
		return;
	}
	int step[4][2] = { 1,0,-1,0,0,1,0,-1 };
	void dfs(vector<vector<char>> board , int x, int y, int m, int n)
	{
		board[x][y] = 1;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + step[i][0];
			int ny = y + step[i][1];
			if (nx >= m || nx < 0 || ny >= n || ny < 0 || board[nx][ny] != 'O' )
				continue;
			dfs(board,  nx, ny, m, n);
		}
		return;
	}
};