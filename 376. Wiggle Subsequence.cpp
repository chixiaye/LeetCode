#include<vector>
#include<queue>
using namespace std;
//��¼������ǰ������Ԫ�ص�״̬��
//��ʼ״̬Ϊbegin �����һ��Ԫ�ش���ǰһ��Ԫ�أ���״̬Ϊup����֮״̬Ϊdown��
//��״̬ת��ʱ��ҡ�����еĳ��ȼ�1
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