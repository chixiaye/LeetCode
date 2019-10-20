#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		vector<int> v(s.length(), 0);
		if (s[0] == '0') return 0; 
		if (s.length() == 1) return 1;
		v[0] = 1;
		v[1] = s[1] != '0';
		if (s[0] == '1'  || s[0] == '2' && s[1] < '7')
			v[1] ++;
		for (int i = 2; i < s.length(); ++i)
		{
			v[i] = s[i] != '0' ? v[i - 1] : 0;
			if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7')
				v[i] += v[i - 2];
		}
		return v[s.length() - 1];
	}
};