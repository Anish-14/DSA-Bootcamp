// https://leetcode.com/problems/partition-list/description/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* tail = NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            if(temp->val < x){
                if(tail == NULL){
                    tail = temp;
                    if(temp != head){
                        prev->next = temp->next;
                        temp->next = head;
                        head = tail;
                        temp = prev->next;
                        continue;
                    }
                }
                else{
                    prev->next = temp->next;
                    temp->next = tail->next;
                    tail->next = temp;
                    temp = prev->next;
                    tail = tail->next;
                    // handeling the case where two consecutive numbers are smaller than x
                    // eg: [1,1] and x = 2
                    if(temp == tail){
                        prev = temp;
                        temp = temp->next;
                    }
                    continue;
                }
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
