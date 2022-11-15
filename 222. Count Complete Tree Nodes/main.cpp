#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(TreeNode* root, int& count) {
    if (root == nullptr)
        return root;
    
    root->left = helper(root->left, count);
    count++;
    root->right = helper(root->right, count);

    return root;
}
int countNodes(TreeNode* root) {
    int count = 0;
    root = helper(root, count);

    return count;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << countNodes(root) << endl;

    return 0;
}
