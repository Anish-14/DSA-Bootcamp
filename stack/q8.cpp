// https://leetcode.com/problems/reorder-list/

class Solution {
public:
    void reorderList(ListNode* head) {

        stack<ListNode*> end;
        queue<ListNode*> start;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            start.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }

        while(slow!= NULL){
            end.push(slow);
            slow = slow->next;
        }

        ListNode* prev = NULL;
        while(!start.empty() && !end.empty()){
            ListNode* first = start.front();
            start.pop();
            ListNode* second = end.top();
            end.pop();

            if(prev != NULL){
                prev->next = first;
            }

            first->next = second;
            second->next = NULL;

            prev = second;
        }

        if(!end.empty() && prev != NULL){
            prev->next = end.top();
            prev->next->next = NULL;
            end.pop();
        }

    }
};



// another solution without using space, here we optimised space as we are not using stack but the TC increases to O(n^2) here.
public:
    ListNode* reverseList(ListNode* head){
        if(!head){return NULL;}
        ListNode* curr = head;
        ListNode* next = head;
        ListNode* prev = NULL;

        while(curr){
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; 
    }

    void reorderList(ListNode* head) {
        if(!head){return;}
        head->next = reverseList(head->next);
        reorderList(head->next);
    }
};
