#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	unordered_map<ListNode*, int> hash;
	while (head) {
		if (hash.find(head) != hash.end())
			return true;
		hash[head] = 1;
		head = head->next;
	}

	return false;
}

int main(){
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 2; i <= 5; i++) {
		p->next = new ListNode(i);
		p = p->next;
	}
	p->next = head->next->next;

	cout << hasCycle(head) << endl;

	return 0;
}