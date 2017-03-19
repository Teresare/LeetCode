//Invert a binary tree.
//
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//to
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1

#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
	if(nullptr == root) return nullptr;
	TreeNode *leftNode = root->left;
	TreeNode *rightNode = root->right;
	root->left = invertTree(rightNode);
	root->right = invertTree(leftNode);
	return root;
}

TreeNode *invertTree(TreeNode *root){
	stack<TreeNode*> istack;
	if(root) istack.push(root);
	while(!istack.empty()){
		TreeNode *cur = istack.top();
		istack.pop();
		if(cur){
			TreeNode *leftNode = cur->left;
			TreeNode *rightNode = cur->right;
			cur->left = rightNode;
			cur->right = leftNode;
			istack.push(leftNode);
			istack.push(rightNode);
		}
	}
	return root;
}