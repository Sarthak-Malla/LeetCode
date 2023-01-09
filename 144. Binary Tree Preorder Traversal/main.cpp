#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> ans;
void helper(TreeNode* root) {
    if (root == nullptr)
        return;
    
    ans.push_back(root->val);
    helper(root->left);
    helper(root->right);
}
vector<int> preorderTraversal(TreeNode* root) {
    helper(root);

    return ans;
}

int main(){
    TreeNode* root->val = 1;
    root->right->val = 2;
    root->right->left->val = 3

    vector<int> ans;
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}