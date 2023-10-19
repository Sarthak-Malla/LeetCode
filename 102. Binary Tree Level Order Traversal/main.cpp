#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

map<int, vector<int>> hash;

void helper(TreeNode* root, int depth) {
	if (!root)
		return;
	
	hash[depth].push_back(root->val);

	helper(root->left, depth + 1);
	helper(root->right, depth + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
	helper(root, 1);
	vector<vector<int>> ans;
	for (auto i = hash.begin(); i != hash.end(); i++)
		ans.push_back(i->second);
	
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int>> ans = levelOrder(root);
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}