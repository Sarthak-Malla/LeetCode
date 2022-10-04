#include<iostream>
using namespace std;

class TreeNode { 
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, int targetSum, int currentSum, bool checker) {
    if (checker)
        return true;

    if (root == nullptr)
        return checker;

    currentSum += root->val;
    
    if (root->left == nullptr && root->right == nullptr)
        return (targetSum == currentSum);

    if (root->left != nullptr) {
        checker = helper(root->left, targetSum, currentSum, checker);
    }
    if (root->right != nullptr) {
        checker = helper(root->right, targetSum, currentSum, checker);
    }

    return checker;
}
bool hasPathSum(TreeNode* root, int targetSum) {
    return helper(root, targetSum, 0, false);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    cout << boolalpha << hasPathSum(root, 22) << endl;

    return 0;
}