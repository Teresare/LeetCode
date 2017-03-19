struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root){
	if(nullptr == root) return 0;
	int leftDepth = 0;
	int rightDepth = 0;
	int rootDepth = 0;
	if(root->left)
		leftDepth = maxDepth(root->left);
	if(root->right)
		rightDepth = maxDepth(root->right);
	if(leftDepth > rightDepth)
		rootDepth = leftDepth + 1;
	else
		rootDepth = rightDepth + 1;
	return rootDepth;
}