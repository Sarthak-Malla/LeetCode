#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int longest = 0;
int helper(TreeNode* root, int depth) {
	if (root == nullptr)
		return -1;
	
	int left = helper(root->left, depth+1) + 1;
	int right = helper(root->right, depth+1) + 1;

	longest = max(longest, left + right);
	return left > right ? left : right;
}
int diameterOfBinaryTree(TreeNode* root) {
	int temp = helper(root, 1);
	return longest;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->left->left = new TreeNode(5);
	root->left->left->left->left = new TreeNode(6);
	root->left->left->left->left->left = new TreeNode(7);
	root->left->left->left->left->left->left = new TreeNode(8);
	root->left->left->left->left->left->left->left = new TreeNode(9);

	cout << diameterOfBinaryTree(root) << endl;

	return 0;
}