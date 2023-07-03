#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	
	ListNode* second = head->next;
	ListNode* curr1 = head;
	ListNode* curr2 = head->next;
	
	while (curr1->next != nullptr && curr1->next->next != nullptr) {
		curr1->next = curr2->next;
		curr1 = curr1->next;
		curr2->next = curr1->next;
		curr2 = curr2->next;
	}
	curr1->next = second;

	return head;
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* curr = head;
	for (int i = 2; i <= 5; i++) {
		curr->next = new ListNode(i);
		curr = curr->next;
	}

	ListNode* ans = oddEvenList(head);
	while (ans != nullptr) {
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;

	return 0;
}