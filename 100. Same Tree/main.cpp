#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}


bool flag = true;
void helper(TreeNode* p, TreeNode* q) {
    // checking if either of the nodes are null, which would mean the two trees are not the same.
    if ((!p && q) || (p && !q)) {
        flag = false;
        return;
    }

    // checking if both of the nodes are null, which could lead to similar trees.
    if (!p || !q)
        return;
    
    // checking if the value at the nodes are same
    if (p->val != q->val) {
        flag = false;
        return;
    }

    // we see if flag is false to stop recursing further
    if (flag) {
        // pre-order traversal
        helper(p->left, q->left);
        helper(p->right, q->right);
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    helper(p, q);
    return flag;
}

int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout<<boolalpha<<isSameTree(p, q)<<endl;

    return 0;
}