#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		f(root, res, 0);
		return res;
	}
	void f(TreeNode* root, vector<vector<int>>& res, int depth)
	{
		if (!root)
			return;
		else
		{
			if (res.size() <= depth)
			{
				vector<int> temp;
				temp.push_back(root->val);
				res.push_back(temp);
			}
			else
				res[depth].push_back(root->val);
			if (root->left)
				f(root->left, res, depth + 1);
			if (root->right)
				f(root->right, res, depth + 1);
		}
	}
};