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
bool ans = false;
void helper(TreeNode* p, TreeNode* q) {
	if (!p && !q)
		return;
	
	if ((!p && q) || (p && !q)) {
		res = false;
		return;
	}

	if (p->val != q->val) {
		res = false;
		return;
	}

	if (res) {
		helper(p->left, q->left);
		helper(p->right, q->right);
	}
}

void anotherHelper(TreeNode* root, TreeNode* subRoot) {
	if (!root)
		return;

	helper(root, subRoot);
	
	ans = ans || res;

	res = true;

	anotherHelper(root->left, subRoot);
	anotherHelper(root->right, subRoot);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	anotherHelper(root, subRoot);
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	
	TreeNode* subRoot = new TreeNode(4);
	subRoot->left = new TreeNode(1);
	subRoot->right = new TreeNode(2);

	cout << isSubtree(root, subRoot) << endl;

	return 0;
}