#include<vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num,0);
		int n = 1;
		for (int i = 1; i < num; ++i)
		{
			if (n <= i) n *= 2;
			int temp = i% (n / 2);
			res[i] = 1 + res[temp];
		}
		return res;
	}
};