#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* cur = res;
    int carry = 0;
    while(l1 || l2){
        int sum = carry;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry) cur->next = new ListNode(carry);
    return res->next;
}

int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* res = addTwoNumbers(l1, l2);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}