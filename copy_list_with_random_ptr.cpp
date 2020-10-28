/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
"""
Step 1: Clone list and fix the next pointers

            |----------------------|
 |----------------------v          v  
[1 -> 1` -> 2 -> 2` ->  3 -> 3` -> 4 -> 4`]

Step 2: Fix the random pointers

            |----------------------|
 |----------------------v          v  
[1 -> 1` -> 2 -> 2` ->  3 -> 3` -> 4 -> 4`]
      @          #           @          #
      @@@@@@@@@@@@@@@@@@@@@@@@          #
                 #                      #
                 ########################
                 
Step 3: Split the cloned list

      |---------|
 |---------v    v
[1 -> 2 -> 3 -> 4]


[1` -> 2` -> 3` -> 4`]
 @     #     @     #
 @@@@@@@@@@@@@     #
       #           #
       #############

"""
*/



class Solution {
public:
    Node* copyRandomList(Node* head) {
        
//         auto current_node = head;
//         map<Node*, Node*> mp;
        
//         //step 1: copy nodes
//         while(current_node) {
//             mp[current_node] = new Node(current_node->val);
//             current_node = current_node->next;
//         }
        
//         //step 2: fix random and next pointers
//         current_node = head;
//         while(current_node) {
//             mp[current_node]->next  = mp[current_node->next];
//             mp[current_node]->random = mp[current_node->random];
//             current_node = current_node->next;
//         }
//         return mp[head];
        if(!head) return NULL;
        
        auto l1 = head;
        Node* l2 = NULL;
        
        
        while(l1) {
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
        }
        
        l1 = head;
        while(l1) {
            if(l1->random) l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }
        
        l1 = head;
        auto l2_head = l1->next;
        while(l1) {
            l2 = l1->next;
            l1->next = l2->next;
            if(l2->next) {
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }
        return l2_head;
    }
};
