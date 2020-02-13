#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> v(1, 1);
		int a[3] = { 2,3,5 };
		int b[3] = { 0,0,0 };
		for (int i = 0; i < n; ++i)
		{
			int m2 = v[b[0]] * 2, m3 = v[b[1]] * 3, m5 = v[b[2]] * 5;
			int mm = min(m2, min(m3, m5));
			if (mm == m2) b[0]++;
			if (mm == m3) b[1]++;
			if (mm == m5) b[2]++;
			v.push_back(mm);
		}
		return v[n - 1];
	}
};
/*����Ҳ����ʹ����С�����������ȷŽ�ȥһ��1��
Ȼ���1������n��ÿ��ȡ���Ѷ�Ԫ�أ�Ϊ��ȷ��û���ظ�����
������һ�� while ѭ��������ʱ�ͶѶ�Ԫ����ͬ�Ķ�ȡ������
Ȼ��ֱ����ȡ�������ֳ��� 2��3��5�����ֱ������С�ѡ�
�������� for ѭ���˳��󣬶Ѷ�Ԫ�ؾ�������ĵ�n����ª����*/