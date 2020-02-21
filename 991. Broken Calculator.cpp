class Solution {
public:
	int brokenCalc(int X, int Y) {
		int res = 0;
		while (X < Y)
		{
			if (Y & 1)
				Y++;
			else
				Y /= 2;
			res++;
		}
		return res + X - Y;
	}
};