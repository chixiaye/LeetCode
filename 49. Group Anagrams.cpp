#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	double prime[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// do not need sort
		unordered_map<double, double> m;
		vector<vector<string>> res;
		int len = strs.size();
		for (int i = 0; i < len; ++i)
		{
			double val = 1;
			for (int j = 0; j < strs[i].length(); ++j)
			{
				val *= prime[strs[i][j] - 'a'];
			}
			if (m.find(val) == m.end())
			{
				m[val] = res.size();
				res.push_back(vector<string>({ strs[i] }));
			}
			else  res[m[val]].push_back(strs[i]);
		}
		return res;
	}
};