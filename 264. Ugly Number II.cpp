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
/*我们也可以使用最小堆来做，首先放进去一个1，
然后从1遍历到n，每次取出堆顶元素，为了确保没有重复数字
，进行一次 while 循环，将此时和堆顶元素相同的都取出来，
然后分别将这个取出的数字乘以 2，3，5，并分别加入最小堆。
这样最终 for 循环退出后，堆顶元素就是所求的第n个丑陋数，*/