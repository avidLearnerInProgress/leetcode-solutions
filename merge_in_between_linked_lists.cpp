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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        
        ListNode *l1start = list1, *l1end, *l2start = list2, *l2end;
        ListNode *l2begPtr, *l2endPtr;
        ListNode *head = list1;
        
        int diff = b - a;
        for(int i = 0; i < a - 1; i++) 
            l1start = l1start->next;
        l2begPtr = l1start;
        
        
        ListNode *tempItr = l1start->next;
        l1start->next = NULL;
        
        cout<<l2begPtr->val<<"--"<<l1start->val<<"\n";
        
        for(int i = 0; i <= diff; i++) {
            tempItr = tempItr->next;
        }
        l2endPtr = tempItr;
        
        while(list2->next) 
            list2 = list2->next;
        l2end = list2;
        
        cout<<l2endPtr->val<<"--"<<l2end->val<<"\n";
        
        l2begPtr->next = l2start;
        l2end->next = l2endPtr;
    
        return head;
        
    }
};
