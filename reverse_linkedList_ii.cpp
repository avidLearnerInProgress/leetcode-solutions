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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
                
                1  ->  2  ->  3  ->  4  ->  5  ->  6
                      mth     m             n     nth
                      prev                        next
            
                1  ->  2      3  <-  4  <-  5      6
                      mth     m             n     nth
                      prev    |             ^     next
                        |-----|-------------|       ^
                              |---------------------|  
                mthprev=>next = n;
                m=>next = nthnext;
                
        */    
        
        ListNode *current = head, *prev = head, *next = head, *mth = NULL, *nth = NULL, *mthPrev = NULL, *nthNext = NULL;
        
        for(int i = 1; current != NULL; i++) {
            //based on standard reverse LL
            
            //keep track of next node when we reverse
            next = current->next; //ncn
                        
            if(i == left) {
                mth = current;
                mthPrev = prev;
            }
            
            //reverse next ptr to point to prev nodes.
            if(i > left and i <= right) {
                current->next = prev; //cnp
            }
            
            if(i == right) {
                nth = current;
                nthNext = next;
            }
            
            prev = current; //pc
            current = next; //cn 
            
        }
        
        if(left == 1) { //if m is the first node in LL
            mth->next = nthNext;
            head = nth;
        }
        else {
            mthPrev->next = nth;
            mth->next = nthNext;
        }
        return head;
    }
};
