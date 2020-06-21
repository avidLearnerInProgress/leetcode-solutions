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
    void reorderList(ListNode* head) {
        deque<ListNode*> d;
        if(head == NULL) return;
        ListNode *temp = head;
        while(temp != NULL){
            d.push_back(temp);
            temp = temp->next;
        }
        d.pop_front(); //since temp = head and we dont need to consider the head again..
        
        while(d.size() > 0){
            
            head->next = d.back();
            d.pop_back();
            head = head->next;
            
            if(d.size() > 0){
                head->next = d.front();
                d.pop_front();
                head = head->next;
            }   
        }
        head->next = NULL;
        
    }
};