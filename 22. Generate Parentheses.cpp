#include <stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	class myclass
	{
	public:
		string str;
		int lp, rp;
		myclass() { lp = rp = 0; };
		void operator =(const myclass &obj)
		{
			//myclass c;
			str = obj.str;
			lp = obj.lp;
			rp = obj.rp;
			//return c;
		}
	};

	vector<string> generateParenthesis(int n) {
		stack<myclass> s;
		vector<string> v;
		myclass temp;
		temp.str = "(";
		temp.lp = 1;
		s.push(temp);
		while (!s.empty())
		{
			temp = (myclass)s.top(); 
			s.pop();
			if (temp.lp+temp.rp < 2 * n)
			{
				myclass t1 = temp, t2= temp; 
				if (t1.lp < n && t1.lp >= t1.rp)
				{
					t1.lp++;
					t1.str += "(";
					s.push(t1);
				}
				if (t2.rp < n && t2.lp >= 1 + t2.rp)
				{
					t2.rp++;
					t2.str += ")";
					s.push(t2);
				}
			}
			else
			{
				v.push_back(temp.str);
			}
		}
		return v;
	}
}; 