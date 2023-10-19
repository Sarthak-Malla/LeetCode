#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool res = true;
int helper(TreeNode* root, int depth) {
	if (root == nullptr)
		return 0;
	
	int left = helper(root->left, depth + 1) + 1;
	int right = helper(root->right, depth + 1) + 1;

	if (abs(left - right) > 1)
		res = false;

	return left > right ? left : right;
}
bool isBalanced(TreeNode* root) {
	int temp = helper(root, 1);
	return res;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = nullptr;
	root->left->right = new TreeNode(3);
	root->right->left = nullptr;
	root->right->right = new TreeNode(3);
	root->left->right->left = new TreeNode(4);
	root->left->right->right = new TreeNode(4);
	cout << isBalanced(root) << endl;

	return 0;
}