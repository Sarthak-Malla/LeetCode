#include<iostream>
#include<list>
using namespace std;

ListNode* middleNode(ListNode* head) {
    int count = 0;
    ListNode* a = head;
    
    while (a != nullptr) {
        count++;
        a = a->next;
    }
    
    int ans = ceil(count/2);
    count = 0;
    
    while (count < ans) {
        head = head->next;
        count++;
    }
    
    return head;
}

int main(){


    return 0;
}