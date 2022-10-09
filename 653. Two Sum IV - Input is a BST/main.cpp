#include<iostream>
#include<unordered_map>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int flag = false;
unordered_map<int, int> hashmap;

TreeNode* helper(TreeNode* root, int target) {
    if (root == nullptr)
        return root;
        
    int curr = target - root->val;
    if (hashmap.find(root->val) == hashmap.end()) {
        hashmap.insert({curr, root->val});
    } else {
        flag = true;
    }

    root->left = helper(root->left, target);
    root->right = helper(root->right, target);

    return root;
}
bool findTarget(TreeNode* root, int k) {
    helper(root, k);

    return flag;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    cout << boolalpha << findTarget(root, 9) << endl;

    return 0;
}