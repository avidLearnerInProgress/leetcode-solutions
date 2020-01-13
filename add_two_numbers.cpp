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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *result = NULL;
        ListNode *head = NULL;
        
        int sum1 = 0, sum2 = 0, sum = 0; 
        bool carry = false;
        
        while(l1 || l2){
            
            if(l1){
                sum1 = l1->val;
                l1 = l1->next;
            }
            else if(!l1)
                sum1 = 0;
            
            if(l2){
                sum2 = l2->val;
                l2 = l2->next;
            }
            else if(!l2)
                sum2 = 0;
            
            if(carry){
                sum = sum1 + sum2 + 1;
                if(sum > 9){
                    carry = true;
                    sum -= 10;
                }
                else{
                    carry = false;
                }
            }
            else
            {
                sum = sum1 + sum2;
                if(sum > 9){
                    sum -= 10;
                    carry = true;
                }
            }
            
            if(sum > 9){
                carry = 1;
                sum -= 10;
            }
            
            if(result == nullptr){
                result = new ListNode(sum);
                head = result;
            }
            else{
                result->next = new ListNode(sum);
                result = result->next;
            }
        }
        cout<<head->val<<"\n";
        cout<<result->val<<"\n";
        if(carry == 1){
            result->next = new ListNode(1);
        }
        return head;
    }
};