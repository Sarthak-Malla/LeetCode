#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* push(ListNode* ans, int n){
    // ListNode* itr = ans;
    // if (ans == nullptr){
    //     ans = new ListNode(n);
    //     return ans;
    // }
    // while (itr->next != nullptr){
    //     itr = itr->next;
    // }
    // itr->next = new ListNode(n);

    ListNode* temp = new ListNode(n);
    temp->next = ans;
    ans = temp;

    return ans;
}

ListNode* rever(ListNode* ans){
    ListNode* head = nullptr;

    while (ans != nullptr){
        head = push(head, ans->val);
        ans = ans->next;
    }

    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* ans = nullptr;
    int carry_over = 0, first_digit, second_digit;
    int the_digit;
    int sum;
    while (l1 != nullptr && l2 != nullptr){
        first_digit = l1->val;
        second_digit = l2->val;

        sum = first_digit + second_digit +  carry_over;
        if (sum > 9){
            the_digit = sum % 10;
            carry_over = sum / 10;
        } else {
            the_digit = sum;
            carry_over = 0;
        }

        ans = push(ans, the_digit);

        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 != nullptr){
        while (l1 != nullptr){
            int digit = l1->val;
            sum = digit + carry_over;
            if (sum > 9){
                the_digit = sum % 10;
                carry_over = sum / 10;
            } else {
                the_digit = sum;
                carry_over = 0;
            }

            ans = push(ans, the_digit);

            l1 = l1->next;
        }
    } 

    if (l2 != nullptr){
        while (l2 != nullptr){
            int digit = l2->val;
            sum = digit + carry_over;
            if (sum > 9){
                the_digit = sum % 10;
                carry_over = sum / 10;
            } else {
                the_digit = sum;
                carry_over = 0;
            }

            ans = push(ans, the_digit);

            l2 = l2->next;
        }
    }

    if (carry_over != 0){
        ans = push(ans, carry_over);
    }

    ans = rever(ans);

    return ans;
}

int main(){
    ListNode l1(2);
    ListNode l2(4);
    // ListNode l3(3);
    ListNode l4(5);
    ListNode l5(6);
    ListNode l6(4);
    l1.next = &l2;
    // l2.next = &l3;

    l4.next = &l5;
    l5.next = &l6;

    ListNode* ans = addTwoNumbers(&l1, &l4);

    while (ans != nullptr){
        cout<<ans->val<<endl;
        ans = ans->next;
    }

    return 0;
}