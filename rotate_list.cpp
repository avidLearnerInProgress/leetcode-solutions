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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next || k == 0) return head;
        
        
        ListNode *current = head;
        int length = 1;
        while(current->next != NULL) {
            current = current->next;
            ++length;
        }
        current->next = head; //point last node to first and make it circular ll to perform rotations
        
        //bring k to nearest multiple ...
        k = k % length; //when k > length
        int end_index = length - k;
        ListNode *last_node = current;
        
        while(end_index--) 
            last_node = last_node->next;
        
        ListNode *first_node = last_node->next;
        last_node->next = NULL;
        
        return first_node;
        
    }
};
