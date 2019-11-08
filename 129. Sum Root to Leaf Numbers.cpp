struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode TreeNode;
int sumNumbers(struct TreeNode* root) {
	if (!root) return 0;
	return f(root, root->val);
}
int f(TreeNode* root, int v)
{
	int a = 0, b = 0;
	if (!root->left && !root->right) return v;
	if (root->left)
		a = f(root->left, 10 * v + root->left->val);
	if (root->right)
		b = f(root->right, 10 * v + root->right->val);
	return a + b;
}
