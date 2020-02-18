#include<vector>
#include<stack>
using namespace std;
/*
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* temp = s.top();
			s.pop();
			res.push_back(temp->val);
			if (temp->right)
				s.push(temp->right);
			if (temp->left)
				s.push(temp->left);
		}
		return res;
	}
};