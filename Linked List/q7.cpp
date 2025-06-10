// https://leetcode.com/problems/linked-list-cycle-ii/description/


class Solution {
public:
    ListNode* isLoop(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow->next;

            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* intersection = isLoop(head);
        if(intersection == NULL){
            return NULL;
        }
        
        ListNode* slow = head;

        while(slow != intersection){
            slow = slow->next;
            intersection = intersection -> next;
        }

        return slow;
    }
};
