#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode* root, TreeNode* low, TreeNode* high) {
	if (!root)
		return true;
	
	if ((low != nullptr && root->val <= low->val) || (high != nullptr && root->val >= high->val))
		return false;

	// true if both left and right are bst
	return (helper(root->left, low, root) && helper(root->right, root, high));
}
bool isValidBST(TreeNode* root) {
	return helper(root, nullptr, nullptr);
}

int main(){
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout << isValidBST(root) << endl;

	return 0;
}