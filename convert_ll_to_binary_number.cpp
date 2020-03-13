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
    int getDecimalValue(ListNode* head) {
        
        int res=0;
        while(head!=NULL) {
            res*=2;
            if(head->val==1) res++;
            head=head->next;
        }
        return res;
        
    }
};