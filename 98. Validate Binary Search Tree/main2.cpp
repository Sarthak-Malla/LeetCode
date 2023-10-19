#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> nums;
void helper(TreeNode* root) {
    if (!root)
        return;
    
    helper(root->left);
    nums.push_back(root->val);
    helper(root->right);
}
bool isValidBST(TreeNode* root) {
    helper(root);
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());

    int n = nums.size();
    for (int i = 0; i < n; i++)
        if (nums[i] != sortedNums[i] || (i > 0 && nums[i] == nums[i-1]))
            return false;

    return true;
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << isValidBST(root) << endl;

    return 0;
}