// https://leetcode.com/problems/merge-k-sorted-lists/
// merge k sorted lists


class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
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
    ListNode* sort(vector<ListNode*>& lists, int s, int e){
        if(s >= e){
            return lists[s];
        }
        int mid = s + (e-s)/2;
        // call for left
        ListNode* left = sort(lists,s,mid);
        ListNode* right = sort(lists,mid+1,e);

        // merge both the lists
        ListNode* ans = merge(left, right);
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0){
            return NULL;
        }

        ListNode* ans = sort(lists,0,size-1);

        return ans;
    }
};
