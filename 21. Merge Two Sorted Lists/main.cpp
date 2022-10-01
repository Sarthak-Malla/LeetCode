#include<iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode();
    ListNode* itr = head;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            itr->next = list1;
            list1 = list1->next;
        } else if (list1->val > list2->val) {
            itr->next = list2;
            list2 = list2->next;
        }
        
        itr = itr->next;
    }
    
    while (list1 != nullptr) {
        itr->next = list1;
        itr = itr->next;
        list1 = list1->next;
    }
    
    while (list2 != nullptr) {
        itr->next = list2;
        itr = itr->next;
        list2 = list2->next;
    }
    
    return head->next;
}

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2); 
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    for (int i = 0; i < 6; i++) {
        cout << mergedList->val << endl;
        mergedList = mergedList->next;
    }

    return 0;
}