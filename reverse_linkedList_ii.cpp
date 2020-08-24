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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(!head) return NULL;
        if(m == n) return head;
        
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        int pos = 1;
        ListNode *nodeBeforeStart = dummy;
        
        while(pos < m) {
            nodeBeforeStart = nodeBeforeStart->next;
            pos++;
        }
        
        
        ListNode *workingPtr = nodeBeforeStart->next;
        while(m < n) {
            ListNode *extractNode = workingPtr->next;
            workingPtr->next = extractNode->next;
            extractNode->next = nodeBeforeStart->next;
            nodeBeforeStart->next = extractNode;
            m++;
        }
        return dummy->next;
    }
};
