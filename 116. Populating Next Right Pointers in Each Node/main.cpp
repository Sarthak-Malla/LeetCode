#include<iostream>
using namespace std;

Node* connect(Node* root) {
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr)
        return root;
    
    root->left->next = root->right;
    root->left = connect(root->left);
    
    if (root->next != nullptr)
        root->right->next = root->next->left;
    
    root->right = connect(root->right);
    
    if (root->right != nullptr && root->next != nullptr)
        root->right->next = root->next->left;
    
    return root;
}

int main(){

    return 0;
}