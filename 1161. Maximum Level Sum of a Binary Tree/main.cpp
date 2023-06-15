#include <bits/stdc++.h>

using namespace std;

int maxLevelSum(TreeNode* root) {
	int level = 1;
	int num_node = 1;
	int ans = INT_MIN;
	int res = 1;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int sum = 0;
		for (int i = 0; i < num_node; i++) {
			TreeNode* curr = q.front();
			q.pop();
			sum += curr->val;

			if (curr->left != nullptr)
				q.push(curr->left);
			if (curr->right != nullptr)
				q.push(curr->right);
		}

		if (sum > ans) {
			ans = sum;
			res = level;
		}

		num_node = q.size();
		level++;
	}

	return res;
}

int main(){
	// Test case 1
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(7);
	root->right = new TreeNode(0);
	root->left->left = new TreeNode(7);
	root->left->right = new TreeNode(-8);

	cout << maxLevelSum(root) << endl;

	return 0;
}