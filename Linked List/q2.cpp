// https://leetcode.com/problems/remove-linked-list-elements/description/
// Remove element from LL

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            if(curr->val == val){
                if(prev == NULL || head->val == val){   // first Node , prev can be non NULL
                    head = curr->next;                  // for head node also, because we are
                }                                       // not deleting the Nodes
                else{
                    prev->next = curr->next;            // head ke alava delete karna
                    curr = curr->next;
                    continue;
                }
            }
            prev = curr;            // normal aage badho
            curr = curr->next;
        }
        return head;
    }
};
