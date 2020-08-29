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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        
        stack<int> s1;
        stack<int> s2;
        
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        auto sum = 0;
        auto first = 0; 
        auto second = 0;
        
        ListNode *result = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();   
            }
            
            result->val = sum % 10; //store sum in result
            ListNode *head = new ListNode(sum / 10); //store remainder in node before current result
            head->next = result;
            result = head;
            sum /= 10;
        }
        return result->val == 0 ? result->next : result;
    }
};
