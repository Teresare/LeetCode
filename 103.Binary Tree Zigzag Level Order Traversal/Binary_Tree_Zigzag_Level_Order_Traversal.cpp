//Given a binary tree, return the zigzag level order traversal of its nodes' values. 
//(ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its zigzag level order traversal as:
//[
//  [3],
//  [20,9],
//  [15,7]
//]

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	queue<TreeNode *> queA, queB;
	vector<vector<int> >ivec;
	if(root) {
		queA.push(root);
		ivec.push_back(vector<int>());
		ivec.back().push_back(root->val);
	}
	for(int i = 0; !queA.empty(); ++i){
		vector<int> ary;
		while(!queA.empty()){
			TreeNode *cur = queA.front();
			if(cur->left) {
				queB.push(cur->left);
				ary.push_back(cur->left->val);
			}
			if(cur->right){
				queB.push(cur->right);
				ary.push_back(cur->right->val);
			}
			queA.pop();
		}
		if(i % 2 == 0){
			reverse(ary.begin(), ary.end());
		}
		if(!ary.empty()){
			ivec.push_back(ary);
		}
		queA.swap(queB);
	}
	return ivec;
}

//标准答案
void traverse(TreeNode *root, size_t level, vector<vector<int> > &result, bool left_to_right){
	if(nullptr == root) return;
	if(level > result.size()){
		result.push_back(vector<int>());
	}
	if(left_to_right){
		result[level - 1].push_back(root->val);
	}else{
		result[level - 1].insert(result[level - 1].begin(), root->val);
	}
	traverse(root->left, level + 1, result, !left_to_right);
	traverse(root->right, level + 1, result, !left_to_right);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int> > result;
	traverse(root, 1, result, true);
	return result;
}

//标准答案
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int> >ivec;
	if(nullptr == root) return ivec;
	queue<TreeNode *> q;
	bool left_to_right = true;
	vector<int> level;
	q.push(root);
	q.push(nullptr);
	while(!q.empty()){
		TreeNode *cur = q.front();
		q.pop();
		if(cur){
			level.push_back(cur->val);
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}else{
			if(left_to_right)
				ivec.push_back(level);
			else{
				reverse(level.begin(), level.end());
				ivec.push_back(level);
			}
			level.clear();
			left_to_right = !left_to_right;
			if(!q.empty()) q.push(nullptr);
		}
	}
}