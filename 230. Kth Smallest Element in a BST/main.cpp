#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> nums;
void helper(TreeNode* root) {
	if (!root)
		return;
	
	helper(root->left);
	nums.push_back(root->val);
	helper(root->right);
}
int kthSmallest(TreeNode* root, int k) {
	helper(root);
	return nums[k - 1];
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	cout << kthSmallest(root, 1) << endl;

	return 0;
}