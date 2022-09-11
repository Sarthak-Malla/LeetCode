#include<iostream>
using namespace std;

// The classes have not been implemented, but this should work when entered into the LeetCode IDE.

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    ListNode* curr = head;
    while (curr != nullptr){
        curr = curr->next;
        count++;
    }
    
    curr = new ListNode();
    curr->next = head;
    head = curr;
    for (int i = 0; i < count - n; i++){
        curr = curr->next;
    }
    
    if (curr->next != nullptr) {
        curr->next = curr->next->next;
    }
    
    return head->next;
}

int main(){

    return 0;
}