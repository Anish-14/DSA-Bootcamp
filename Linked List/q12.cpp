// https://leetcode.com/problems/sort-list/description/
// sort the LL


class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* ans = new ListNode(-1);   // dummy
        ListNode* curr = ans;

        while(left && right){
            if(left->val <= right->val){
                curr->next = new ListNode(left->val);
                left = left->next;
            }
            else{
                curr->next = new ListNode(right->val);
                right = right->next;
            }
            curr = curr->next;
        }
        while(left){
            curr->next = new ListNode(left->val);
            left = left->next;
            curr = curr->next;
        }
        while(right){
            curr->next = new ListNode(right->val);
            right = right->next;
            curr = curr->next;
        }

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        // merge sort in LL
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;      // seperate the LL in two halves

        // sort left && right
        ListNode* leftHead = sortList(head);
        ListNode* rightHead = sortList(slow);

        ListNode* ans = merge(leftHead, rightHead);

        return ans;
    }
};
