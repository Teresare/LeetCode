#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
vector<TreeNode *> generate(int begin, int end){
	vector<TreeNode *> subTree;
	if(begin > end){
		subTree.push_back(nullptr);
		return subTree;
	}

	for(int k = begin; k != end + 1; ++k){
		vector<TreeNode *> leftSubTree = generate(begin, k - 1);
		vector<TreeNode *> rightSubTree = generate(k + 1, end);

		for(auto i : leftSubTree){
			for(auto j : rightSubTree){
				TreeNode *kNode = new TreeNode(k);
				kNode->left = i;
				kNode->right = j;
				subTree.push_back(kNode);
			}
		}
	}

	return subTree;
}
vector<TreeNode*> generateTrees(int n) {
	if(0 == n) return vector<TreeNode *>();
	return generate(1, n);
}