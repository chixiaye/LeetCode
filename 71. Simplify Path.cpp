#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		stack<string> s;
		for (int i = 0; i < path.length(); ++i)
		{
			if (path[i] == '/')
			{
				string temp;
				int j;
				for (j = i + 1; j < path.length() && path[j] != '/'; ++j)
				{
					temp += path[j];
				}
				i = j - 1;
				if (temp != "" && temp != ".." && temp != ".")
				{
					s.push(temp);
				}
				else
				{
					int len = temp.size() - 1;
					while (len > 0 && !s.empty())
					{
						s.pop();
						len--;
					}
				}
			}
		}
		string res;
		while (!s.empty())
		{
			res = '/' + s.top() + res;
			s.pop();
		}
		return res.empty() ? "/" : res;
	}
};