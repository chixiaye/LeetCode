#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int P) {
		sort(tokens.begin(), tokens.end());
		int up = tokens.size() - 1, down = 0;
		int point = 0, maxPoint = 0;
		while (down <= up)
		{
			if (tokens[down] <= P)
			{
				P -= tokens[down++];
				point++;
				maxPoint = max(maxPoint, point);
			}
			else if (point == 0)
				break;
			else
			{
				point--;
				P += tokens[up--];
			}
		}
		return maxPoint;
	}
};