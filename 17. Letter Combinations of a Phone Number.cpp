#include<map>
#include<string> 
#include<vector> 
using namespace std;
class Solution {
public:
	//map<string, int>m;
	map<int, string >m;
	Solution() {/*
		m["a"] = 2, m["b"] = 2, m["c"] = 2,
			m["d"] = 3, m["e"] = 3, m["f"] = 3,
			m["g"] = 4, m["h"] = 4, m["i"] = 4,
			m["j"] = 5, m["k"] = 5, m["l"] = 5,
			m["m"] = 6, m["n"] = 6, m["o"] = 6,
			m["p"] = 7, m["q"] = 7, m["r"] = 7, m["s"] = 7,
			m["t"] = 8, m["u"] = 8, m["v"] = 8,
			m["w"] = 9, m["x"] = 9, m["y"] = 9, m["z"] = 9;*/
		m[2] = "abc", m[3] = "def", m[4] = "ghi", m[5] = "jkl", m[6] = "mno",
			m[7] = "pqrs", m[8] = "tuv", m[9] = "wxyz";
	} 
	vector<string> letterCombinations(string digits) {
		int len = digits.size();
		vector<string> res;
		dfs(res, len, 0, "", digits);
		return res;
	}
	void dfs(vector<string>& v, int len, int cur, string str, string digits) {
		if (cur == len && len > 0) {
			v.push_back(str);
			return;
		} 
		string s = m[digits[cur] - '0'];
		int slen = s.size();
		for (int i = 0; i < slen; ++i)
			dfs(v, len, cur + 1, str + s[i], digits);
	}
};