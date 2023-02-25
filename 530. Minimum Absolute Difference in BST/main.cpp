#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> nums;
void helper(TreeNode *root) {
	if (!root)
		return;
	
	helper(root->left);
	nums.push_back(root->val);
	helper(root->right);
}
int getMinimumDifference(TreeNode* root) {
	helper(root);
	int n = nums.size();
	int m = INT_MAX;
	for (int i = 1; i < n; i++)
		m = min(m, nums[i] - nums[i-1]);

	return m;
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);

	cout << getMinimumDifference(root) << endl;

	return 0;
}