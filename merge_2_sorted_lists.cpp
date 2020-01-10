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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 == NULL && l2 == NULL) return NULL;
        
        ListNode *d = new ListNode(0);
        ListNode *dummy = d;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                d->next =l1;
                l1 = l1->next;
            }
            else{
                d->next =l2;
                l2 = l2->next;
            }
            d = d->next;
        }
        if(l1){
        while(l1){
            d->next = l1;
            l1 = l1->next;
            d = d->next;
        }
        }
        
        if(l2){
        while(l2){
            d->next = l2;
            l2 = l2->next;
            d = d->next;
        }
        }
        return dummy->next;
    }
};