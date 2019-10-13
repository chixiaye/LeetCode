#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int len = s.length();
		vector<int> res(4, 0);
		vector<string> ans;
		if (!len)
			return ans;

		for (int i = 1; i < len && i < 4; ++i)
		{
			for (int j = i + 1; j < len && j < i + 4; ++j)
			{
				for (int k = j + 1; k < len && k < j + 4; ++k)
				{
					string sub[4];
					sub[0] = s.substr(0, i);
					sub[1] = s.substr(i, j - i);
					sub[2] = s.substr(j, k - j);
					sub[3] = s.substr(k, len - k);
					int flag = true;
					for (int m = 0; m < 4; ++m)
						res[m] = atoi(sub[m].c_str());

					for (int m = 0; m < 4; ++m)
					{

						if (res[m] > 255 || res[m] < 0)
						{
							flag = false;
							break;
						} 
					} 
					for (int m = 0; m < 4; ++m)
					{
						if (sub[m].length() == 2)
						{
							if (sub[m][0] == '0')
								flag = false;
						}
						else if (sub[m].length() == 3)
						{
							if (sub[m][0] == '0')
								flag = false;
						}
						else if (sub[m].length() > 3)
							flag = false;
					}
					if (flag)
					{
						string temp;
						for (int m = 0; m < 3; ++m)
						{
							temp += sub[m] + ".";
						}
						temp += sub[3];
						ans.push_back(temp);
					}
				}
			}
		}
		return ans;
	}
};