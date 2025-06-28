// https://leetcode.com/problems/rotate-list/


class Solution {
public:
    int sizeLL(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }

        int size = sizeLL(head);
        k = k % size;
        if(k == 0){
            return head;
        }
        
        ListNode* newtail = head;
        for(int i = 0; i<size-k-1; i++){
            newtail = newtail->next;
        }

        ListNode* newhead = newtail->next;

        ListNode* oldtail = newtail;
        while(oldtail->next != NULL){
            oldtail = oldtail -> next;
        }

        // now break the LL 
        oldtail->next = head;
        newtail->next = NULL;

        return newhead;
    }
};
