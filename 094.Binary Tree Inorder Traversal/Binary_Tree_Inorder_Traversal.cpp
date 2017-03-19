//Binary Tree Inorder Traversal
//
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [1,3,2].
//
//Note: Recursive solution is trivial, could you do it iteratively?

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void subInorderTraversal(TreeNode* node, vector<int> &ivec){
	if(nullptr == node) return;
	subInorderTraversal(node->left, ivec);
	ivec.push_back(node->val);
	subInorderTraversal(node->right, ivec);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ivec;
	subInorderTraversal(root, ivec);
	return ivec;
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ivec;
	stack<TreeNode*> istack;
	while(root){
		istack.push(root);
		root = root->left;
	}
	istack.push(nullptr);
	while(!istack.empty()){
		TreeNode * temp;
		temp = istack.top();
		istack.pop();
		if(temp) ivec.push_back(temp->val);
		if(istack.empty()) break;
		temp = istack.top();
		istack.pop();
		if(temp) ivec.push_back(temp->val);
		temp = temp->right;
		while(temp){
			istack.push(temp);
			temp = temp->left;
		}
		istack.push(nullptr);
	}
	return ivec;
}

//��������������㷨����׼��
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> result;
	const TreeNode *p = root;
	stack<const TreeNode *> s;
	while (!s.empty() || p != nullptr) {
		if (p != nullptr) {
			s.push(p);
			p = p->left;
		} else {
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}

//��������������㷨����׼�𰸣�Mirrors
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> result;
	TreeNode *cur, *prev;
	cur = root;
	while (cur != nullptr) {
		if (cur->left == nullptr) {
			result.push_back(cur->val);
			prev = cur;
			cur = cur->right;
		} else {
			/* ����ǰ�� */
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur)
				node = node->right;
			if (node->right == nullptr) { /* ��û���������������� */
				node->right = cur;
				/* prev = cur; ��������䣬 cur ��û�б����� */
				cur = cur->left;
			} else { /* �Ѿ�������������ʽڵ㣬��ɾ������ */
				result.push_back(cur->val);
				node->right = nullptr;
				prev = cur;
				cur = cur->right;
			}
		}
	}
	return result;
}