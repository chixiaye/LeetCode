#include<string>
using namespace std;
class Solution {
public:
	bool isValid(string S) {
		for (size_t index = S.find("abc"); index != string::npos; index = S.find("abc"))
		{
			S.erase(S.begin() + index, S.begin() + index + 3);
		}
		return S.empty();
	}
};