#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		vector<vector<int>>res;
		vector<int>  temp1(colsum.size(), 0);
		vector<int>  temp2(colsum.size(), 0);
		for (int i = 0; i < colsum.size(); ++i)
		{
			if (colsum[i] >= 3 || lower < 0 || upper < 0)
				return res;
			else if (colsum[i] == 1)
			{
				if (upper > lower)
				{
					upper--;
					temp1[i] = 1;
				}
				else
				{
					lower--;
					temp2[i] = 1;
				}
			}
			else if (colsum[i] == 2)
			{
				upper--, lower--;
				temp1[i] = 1, temp2[i] = 1;
			}
		}
		if (lower != 0 || upper != 0)
			return res;
		else
		{
			res.push_back(temp1);
			res.push_back(temp2);
			return res;
		}
	}
};