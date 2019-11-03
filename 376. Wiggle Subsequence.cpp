#include<vector>
#include<queue>
using namespace std;
//记录序列中前后两个元素的状态。
//初始状态为begin 如果后一个元素大于前一个元素，则状态为up，反之状态为down。
//当状态转换时，摇摆序列的长度加1
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int pre = -1,res=1,state=0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i - 1] > nums[i] && (state>=0))
			{
				state = -1;
				res++;
			}
			else if (nums[i - 1] < nums[i]&&(state<=0))
			{
				state = 1;
				res++;
			}
		}
		return res;
	}
};