#include<iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* curr = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return curr;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* curr = reverseList(head);
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;


    return 0;
}