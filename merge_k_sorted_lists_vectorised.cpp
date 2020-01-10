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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        map<int, int> m; //value-count
        ListNode* it;
        
        for(ListNode *lst: lists){
            it = lst;
            while(it != NULL){
                m[it->val]++;
                it = it->next;
            }
        }
        
        auto ltr = new ListNode(0);
        auto head = ltr;
        
        for(pair p : m){
            for(auto i=0; i<p.second; i++){
                ltr->next = new ListNode(p.first);
                ltr = ltr->next;
            }
        }
        return head->next;
    }
};