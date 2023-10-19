#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* ans = new TreeNode();
TreeNode* p_ = new TreeNode();
TreeNode* q_ = new TreeNode();
bool flag = false;
void helper(TreeNode* root) {
	if (!root || flag)
		return;
	
	if (root->left == nullptr && root->right == nullptr)
		return;
	
	helper(root->left);
	helper(root->right);

	if ((root->left == p_ && root->right == q_) || (root->left == q_ && root->right == p_) || (root == p_ && (root->left == q_ || root->right == q_)) || (root == q_ && (root->left == p_ || root->right == p_))) {
		flag = true;
		ans = root;
	}

	if (root->left == p_ || root->right == p_)
		p_ = root;
	else if (root->left == q_ || root->right == q_)
		q_ = root;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	p_ = p;
	q_ = q;
	helper(root);
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	TreeNode* p = new TreeNode(5);
	TreeNode* q = new TreeNode(4);

	TreeNode* ans = lowestCommonAncestor(root, p, q);
	cout << ans->val << endl;

	return 0;
}