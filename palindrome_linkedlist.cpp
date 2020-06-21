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
    ListNode *reverse(ListNode* head){
        //if(!head) return NULL;
        ListNode *next = NULL, *prev = NULL;
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        //head = prev;
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return true;
        ListNode *fastptr = head, *slowptr = head;
        
        while(fastptr->next != NULL && fastptr->next->next != NULL){
            slowptr  = slowptr->next;
            fastptr = fastptr->next->next;
        }
        slowptr->next = reverse(slowptr->next);
        slowptr = slowptr->next; //slow == pre here.. now compare
        
        while(slowptr!=NULL){
            if(head->val != slowptr->val)return false;
            slowptr = slowptr->next;
            head = head->next;
        }
        return true;
    }
};