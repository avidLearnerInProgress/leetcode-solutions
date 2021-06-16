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
    ListNode* swapNodes(ListNode* head, int k) {
        if(k == 0) return head;
        
        ListNode *slow, *kthBegin, *fast = head;
        
        for(int i = 0; i < k; i++) {
            kthBegin = fast;
            fast = fast->next;
        }
        
        slow = head;    
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        cout<<kthBegin->val<<" "<<slow->val<<" ";
        swap(slow->val, kthBegin->val);

        return head;
       
    }
};
