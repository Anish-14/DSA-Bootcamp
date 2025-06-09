// https://leetcode.com/problems/reverse-linked-list/description/
// reverse the LL

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // iterative way
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};


// Recursive way 1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       // recursive way
        if(head == NULL || head -> next == NULL){
                return head;
        }
        ListNode* temp = head;
        ListNode* chhotaHead = reverseList(head->next);
        temp->next->next = temp;
        temp->next = NULL;
        return chhotaHead;
    }
};

// Recursive way 2
class Solution {
public:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
        if(curr == NULL){
            head = prev;
            return ;
        }

        reverse(head,curr->next,curr);
        curr->next = prev;
    }
    
    ListNode* reverseList(ListNode* head) {
       // recursive way
        if(head == NULL || head -> next == NULL){
                return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;  
        reverse(head,curr,prev);
        return head;
    }
};
