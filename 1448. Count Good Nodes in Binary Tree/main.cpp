#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

int ans = 0;
void helper(TreeNode* root, int max_) {
	if (!root)
		return;
	
	if (root->val >= max_)
		ans++;
	
	helper(root->left, max(max_, root->val));
	helper(root->right, max(max_, root->val));
}
int goodNodes(TreeNode* root) {
	helper(root, root->val);
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(3);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(5);

	cout << goodNodes(root) << endl;

	return 0;
}