#include <bits/stdc++.h>

using namespace std;

void helper(TreeNode* root) {
	if (root == nullptr)
		return;
	
	helper(root->left);
	helper(root->right);
	
	TreeNode* temp = root->right;
	root->right = root->left;
	root->left = temp;
}

TreeNode* invertTree(TreeNode* root) {
	helper(root);

	return root;
}

int main(){
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	TreeNode* root = invertTree(root);

	return 0;
}