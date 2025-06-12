// https://leetcode.com/problems/add-two-numbers/description/
// add two numbers represented by the LL
// pehle se hi reverse order karke diya hua hai

class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            int val = sum%10;
            carry = sum/10;

            curr->next = new ListNode(val);
            curr = curr->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            int val = sum%10;
            carry = sum/10;

            curr->next = new ListNode(val);
            curr = curr->next;

            l1 = l1->next;
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            int val = sum%10;
            carry = sum/10;

            curr->next = new ListNode(val);
            curr = curr->next;

            l2 = l2->next;
        }
        while(carry){
            int val = carry%10; 
            carry = carry/10;

            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy->next;
    }
};
