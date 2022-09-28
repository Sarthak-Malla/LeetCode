#include<iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* curr = head;
    if (!curr)
        return 0;
    int n = 1;
    while (curr->next != nullptr) {
        n++;
        curr = curr->next;
    }
    
    curr->next = head;
    
    k = k % n;
    for (int i = 0; i < n - k; i++) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = nullptr;
    
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 5; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    
    curr = rotateRight(head, 2);
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}