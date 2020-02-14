#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int candy(vector<int>& ratings) {
		int res = 0;
		vector<int> temp(ratings.size(), 1);
		for (int i = 0; i < ratings.size(); ++i)
		{
			if (i > 0 && ratings[i] > ratings[i - 1])
			{
				temp[i] = temp[i - 1] + 1;
			}
		}
		for (int i = ratings.size() - 1; i > 0; i--)
		{
			if (ratings[i - 1] > ratings[i])
				temp[i - 1] = max(temp[i] + 1, temp[i - 1]);
			res += temp[i];
		}
		return res + temp[0];
	}
};