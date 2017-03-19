//Flatten Binary Tree to Linked List
//
//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6

#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//void flatten(TreeNode* root) {
//	if(nullptr == root) return;
//	flatten(root->left);
//	flatten(root->right);
//	if(nullptr == root->left) return;
//	TreeNode *p = root->left;
//	while(p->right) p = p->right;
//	p->right = root->right;
//	root->right = root->left;
//	root->left = nullptr;
//}

TreeNode *subFlatten(TreeNode *root, TreeNode *tail){
	if(nullptr == root) return tail;
	root->right = subFlatten(root->left, subFlatten(root->right, tail));
	root->left = nullptr;
	return root;
}

void flatten(TreeNode *root){
	subFlatten(root, nullptr);
}

//void flatten(TreeNode *root){
//	if(nullptr == root) return;
//	stack<TreeNode *> s;
//	s.push(root);
//	while(!s.empty()){
//		TreeNode *p = s.top();
//		s.pop();
//		if(p->right) s.push(p->right);
//		if(p->left) s.push(p->left);
//		p->left = nullptr;
//		if(!s.empty()) p->right = s.top();
//
//	}
//}

int main(){
	TreeNode first(1), second(2), third(3);
	first.left = &second, first.right = &third;
	flatten(&first);
	return 0;
}