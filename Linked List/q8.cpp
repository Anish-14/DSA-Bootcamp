
// https://leetcode.com/problems/odd-even-linked-list/description/
// Odd Even LL

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* currOdd = odd;
        ListNode* currEven = even;
        ListNode* prev = odd;
        while(currOdd){
            prev = currOdd;
            if(currEven){
                currOdd->next = currEven->next;
                currOdd = currOdd->next;
                if(currOdd){
                    currEven->next = currOdd->next;
                    currEven = currEven->next;
                }
            }
            else{
                break;
            }
        }

        prev->next = even;

        return odd;
    }
};


// another solution without unnecessary lines of code i.e. good quality code

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
           return head;
        int count = 0;
        ListNode* temp = head;
        while(temp)
            count++, temp = temp->next;
        ListNode* curr = head;
        ListNode* next = head->next;
        temp = head->next;
        while((next != nullptr && count%2 == 1) || (count%2 == 0 &&next->next != nullptr)){
            curr->next = next->next;
            curr = next;
            next = next->next;
        }
        curr->next = temp;
        return head;
    }
};

