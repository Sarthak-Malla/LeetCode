#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// tracks the total sum of the tree
int sum = 0;

// tracks the sum of the nodes that have been visited
int curr_sum = 0;

// helper function to calculate the sum of the tree
void helper(TreeNode *root) {
	if (!root)
		return;

	helper(root->left);
	sum += root->val;
	helper(root->right);
}

// helper function to make the greater tree
void make_greater_tree(TreeNode *root) {
	if (!root)
		return;
	make_greater_tree(root->left);
	// temporarily store the value of the node
	int temp = root->val;

	// update the value of the node such that we take out the sum of the nodes that have been visited from the total sum
	root->val = sum - curr_sum;

	// update the curr_sum to take the sum of the nodes that have been visited
	curr_sum += temp;
	make_greater_tree(root->right);

}
TreeNode* convertBST(TreeNode* root) {
	helper(root);
	make_greater_tree(root);

	return root;
}

int main(){
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(13);
	convertBST(root);

	return 0;
}