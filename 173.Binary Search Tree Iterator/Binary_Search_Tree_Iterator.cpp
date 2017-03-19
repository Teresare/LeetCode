//Binary Search Tree Iterator
//
//Implement an iterator over a binary search tree (BST). 
//Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
//where h is the height of the tree.

#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root){
			istack.push(root);
			root = root->left;
		}
    }

    //@return whether we have a next smallest number
    bool hasNext() {
        return !istack.empty();
    }

    //@return the next smallest number
    int next() {
		TreeNode *p;
		p = istack.top();
		istack.pop();
		int result = p->val;
		p = p->right;
		while(p){
			istack.push(p);
			p = p->left;
		}
		return result;
    }
private:
	stack<TreeNode*> istack;
};

//Your BSTIterator will be called like this:
//BSTIterator i = BSTIterator(root);
//while (i.hasNext()) cout << i.next();