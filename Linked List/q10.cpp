// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// remove the nth node from the end

class Solution {
public:
    int getSize(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        int num = size - n;         // numth node to delete
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(num--){
            prev = curr;
            curr = curr->next;
        }
        
        if(prev != NULL){
            prev->next = curr->next;
        }
        else{   // first digit
            head = curr->next;
        }
        
        return head;
    }
};
