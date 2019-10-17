#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int color[3] = {0,0,0};
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			color[nums[i]]++;
		}
		int k = 0;
		for (int i = 0; i < len; ++i)
		{
			while (color[k] == 0);
				k++;
			nums[i] = color[k];
			color[k]--;
		}
	}
};
//Ë«Ö¸Õë
class Solution {
public:
	void sortColors(vector<int>& A) {
		int second = A.size() - 1, zero = 0;
		for (int i = 0; i <= second; i++) {
			while (A[i] == 2 && i < second) swap(A[i], A[second--]);
			while (A[i] == 0 && i > zero) swap(A[i], A[zero++]);
		}
	}
};