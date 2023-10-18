#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int max_ = 0;
void helper(TreeNode* root, int depth) {
	if (root == nullptr)
		return;
	max_ = max(depth, max_);

	helper(root->left, depth+1);
	helper(root->right, depth+1);
}
int maxDepth(TreeNode* root) {
	helper(root, 1);

	return max_;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);

	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	cout << maxDepth(root) << endl;

	return 0;
}