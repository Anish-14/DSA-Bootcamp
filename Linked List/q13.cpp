// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// reverse nodes in k group


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        bool check = true;
        for(int i = 0; i<k; i++){
            if(temp == NULL){
                check = false;
                break;
            }
            temp = temp->next;
        }
        if(!check){
            return head;
        }

        // call the function
        ListNode* newHead = reverseKGroup(temp, k);

        // reverse the current k nodes
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        for(int i = 0; i<k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = newHead;
        return prev;
    }
};
