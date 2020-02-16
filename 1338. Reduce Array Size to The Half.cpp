#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minSetSize(vector<int>& arr) {
		int res = 0, num = 0;
		vector<int> m(100000, 0);
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] < 100000)
				m[arr[i]]++;
		}
		sort(m.begin(), m.end(), greater<int>());
		for (int i = 0; i < m.size() && m[i] != 0; ++i)
		{
			if (res + m[i] >= arr.size() / 2)
			{
				return num + 1;
			}
			else
			{
				res += m[i];
				num++;
			}
		}
		return 0;
	}
};