//Minimum Depth of Binary Tree
//
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path 
//from the root node down to the nearest leaf node.

#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//迭代版（标准答案）
int minDepth(TreeNode *root){
	if(nullptr == root) return 0;
	stack<pair<TreeNode *, int>> istack;
	istack.push(make_pair(root, 1));
	int result = INT_MAX;
	while(!istack.empty()){
		TreeNode *curNode = istack.top().first;
		int curDeep = istack.top().second;
		istack.pop();
		if(nullptr == curNode->left && nullptr == curNode -> right)
			result = min(result, curDeep);
		if(curNode->left && result > curDeep) 
			istack.push(make_pair(curNode->left, curDeep + 1));
		if(curNode->right && result > curDeep) 
			istack.push(make_pair(curNode->right, curDeep + 1));
	}
	return result;
}

//迭代版（自己写）
int minDepth(TreeNode* root) {
	if(nullptr == root) return 0;
	queue<TreeNode *> trqueue;
	int deep = 1;
	trqueue.push(root);
	while(!trqueue.empty()){
		queue<TreeNode *> temp;
		while(!trqueue.empty()){
			TreeNode *cur = trqueue.front();
			trqueue.pop();
			if(nullptr == cur->left && nullptr == cur->right) return deep;
			if(cur->left) temp.push(cur->left);
			if(cur->right) temp.push(cur->right);
		}
		trqueue.swap(temp);
		++deep;
	}
}

//递归版（标准答案）
int subMinDepth(TreeNode *root, bool hasbrother){
	if(!root) return hasbrother ? INT_MAX : 0;
	return 1 + min(subMinDepth(root->left, root->right != nullptr), 
		subMinDepth(root->right, root->left != nullptr));
}

int minDepth(TreeNode* root) {
	return subMinDepth(root, false);
}

//递归版（自己写)
int minDepth(TreeNode *root){
	if(nullptr == root)
		return 0;
	else if(root->left && root->right)
		return 1 + min(minDepth(root->left), minDepth(root->right));
	else if(root->left)
		return 1 + minDepth(root->left);
	else
		return 1 + minDepth(root->right);
}