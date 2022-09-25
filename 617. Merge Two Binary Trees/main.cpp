#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    
    if (root1 != nullptr && root2 != nullptr)
        root1->val = root1->val + root2->val;
    
    return root1;
}

int main(){

    return 0;
}