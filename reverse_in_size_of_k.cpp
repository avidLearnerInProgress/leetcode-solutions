/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head){
        if(!head) return NULL;
        int c = 0;
        while(head){
            c++;
            head = head->next;
        }
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0 || count(head) < k) return head;
        
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int c = 0;
        while(curr != NULL && c <k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        if(next != NULL)
            head->next = reverseKGroup(next, k);
        return prev;
    }  
};