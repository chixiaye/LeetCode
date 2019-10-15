#include<vector>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		int size = pow(2, n);
		vector<int> ans(size,0);
		for (int i = 0; i < size; ++i)
		{
			ans[i] = i ^( i >> 1);
		}
		return ans;
	}
};