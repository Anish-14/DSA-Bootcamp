// https://leetcode.com/problems/merge-two-sorted-lists/description/
// Merge two sorted LL without using any extra space

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* head = new ListNode(-1);          // dummy node
        ListNode* ans = head;

        while(first && second){
            if(first->val <= second->val){
                head->next = first;
                head = head->next;
                first = first->next;
            }
            else{
                head->next = second;
                head = head->next;
                second = second->next;
            }
        }
        while(first){
            head->next = first;
            head = head->next;
            first = first->next;
        }
        while(second){
            head->next = second;
            head = head->next;
            second = second->next;
        }

        return ans->next;
    }
};
