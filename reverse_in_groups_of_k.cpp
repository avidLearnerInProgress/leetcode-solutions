/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode *start, ListNode *end) {
        
        //check the prev initialization
        ListNode *current = start, *next = NULL, *prev = end;
        
        while(current != NULL && current != end) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode *curr = head;
        int count = 0;
        while(count < k) {
            if(!curr) return head; //case when k = 3, and number of nodes in current group is < k
            curr = curr->next;
            count++;
        }
        ListNode* next_head = reverse(head, curr);  // standard reverse call, after reversing we get new head, [1,2,3] => [3,2,1] so new head is 3
        head->next = reverseKGroup(curr, k); //head points to 1 above, so first k group is reversed; now we look for next kth group
        return next_head; //we keep returning new head which is going to be the start of reversed groups and at the end of all recursive calls, we will have next_head as first element of node in linked list
        
        
        /* 
        k = 3
        [1,2,3,4,5,6,7,8,9,10,11,12,13,14]   
        [1,2,3]         => [3,2,1], next_head = 3, head = 1, head->next = (1) := 6th entry point
        [4,5,6]         => [6,5,4], next_head = 6, head = 4, head->next = (2) := 5th entry point
        [7,8,9]         => [9,8,7], next_head = 9, head = 7, head->next = (3) := 4th entry point
        [10,11,12]      => [12,11,10], next_head = 12, head = 10, head->next = (4) := 3rd entry point
        [13,14]         => [13,14], next_head = 13, head = 13, head->next = (5) := 2nd entry point
        [13,14]         => [13,14], next_head = 14, head = 14, head->next = NULL  := 1st entry point
        */
    }
};              
