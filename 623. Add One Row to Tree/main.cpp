#include<iostream>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    depth--;

    if (root == nullptr)
        return nullptr;

    if (!depth) {
        TreeNode* n_root = new TreeNode(val);
        n_root->left = root;

        return n_root;
    }
    
    if (depth == 1) {
        TreeNode* left_node = new TreeNode(val);
        left_node->left = root->left;
        root->left = left_node;
        
        TreeNode* right_node = new TreeNode(val);
        right_node->right = root->right;
        root->right = right_node;

        return root;
    }

    if (root->left != nullptr)
        root->left = addOneRow(root->left, val, depth);
    
    if (root->right != nullptr)
        root->right = addOneRow(root->right, val, depth);

    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);

    root = addOneRow(root, 1, 2);
    printTree(root);

    return 0;
}