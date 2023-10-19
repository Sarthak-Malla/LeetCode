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

vector<int> rightSideView(TreeNode* root) {
	helper(root, 1);
	vector<int> ans;
	for (auto i = hash.begin(); i != hash.end(); i++)
		ans.push_back(i->second[i->second.size() - 1]);
	
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	vector<int> ans = rightSideView(root);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}