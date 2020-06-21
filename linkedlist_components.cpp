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
    int numComponents(ListNode* head, vector<int>& G) {
        /*
        a. using set
        b. using map
        */
        unordered_set<int> ust(G.begin(), G.end());
        ListNode *node = head;
        int uniq_val_int = 0;
        
        while(node != NULL){
            if(ust.find(node->val) != ust.end()){
                uniq_val_int++;
                while(node->next && ust.find(node->next->val) != ust.end()){
                    node = node->next;
                }
            }
            node = node->next;
        }
        return uniq_val_int;
        
        
    }
};


/*
     std::bitset<10000> hash;    
        for (int g : G) {
            hash.set(g);
        }
        
        int result = 0;
        while (head) {
            if (hash.test(head->val)) {
                result++;
            }
            
            while (head && hash.test(head->val)) {
                head = head->next;
            }
            
            if (head) {
                head = head->next;
            }
        }
        
        return result;
    }
};

auto fast = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
*/