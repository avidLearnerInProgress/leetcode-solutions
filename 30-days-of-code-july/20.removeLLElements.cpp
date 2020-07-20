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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == nullptr) return head;
        
        while(head != nullptr && head->val == val)
            head = head->next;
            
        
        ListNode* q = nullptr, *p = head;
        
        while(p != nullptr) {
            if(p->val == val) {
                q->next = p->next;
                p = p->next;
            }
            else {
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};
