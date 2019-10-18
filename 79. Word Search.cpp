#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (!m) return false;
		int n = board[0].size();
		if (!n) return false;
		if (word.length() == 0) return true;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (word[0] == board[i][j])
				{
					 
					bool flag = false;
					f(board, word,    1, i, j, flag);
					if (flag) return true;
				}
			}
		}
		return false;
	}
	int step[4][2] = { 0,1,0,-1,1,0,-1,0 };
	void f(vector<vector<char>> board, string word,  int cur, int x, int y, bool& flag)
	{

		if (flag || cur == word.length())
		{
			flag = true;
			return;
		}
		for (int i = 0; !flag && i < 4; ++i)
		{
			if (step[i][0] + x < board.size() && step[i][1] + y < board[0].size() && step[i][0] + x >= 0 && step[i][1] + y >= 0 &&   word[cur] == board[x + step[i][0]][y + step[i][1]])
			{
				board[step[i][0] + x][step[i][1] + y] = 0;
				f(board, word,   cur + 1, step[i][0] + x, step[i][1] + y, flag);
				board[step[i][0] + x][step[i][1] + y] = word[cur];
			}
		}
	}
};