#include<iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode* curr = head;
    ListNode* behind = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        curr = curr->next;
        if (behind->next->next == curr)
            behind = behind->next;
    }

    behind->next = curr->next;
    delete curr;

    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 5; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    head = deleteMiddle(head);
    curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
