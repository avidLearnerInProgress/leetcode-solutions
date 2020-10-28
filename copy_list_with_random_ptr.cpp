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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        auto current_node = head;
        map<Node*, Node*> mp;
        
        //step 1: copy nodes
        while(current_node) {
            mp[current_node] = new Node(current_node->val);
            current_node = current_node->next;
        }
        
        //step 2: fix random and next pointers
        current_node = head;
        while(current_node) {
            mp[current_node]->next  = mp[current_node->next];
            mp[current_node]->random = mp[current_node->random];
            current_node = current_node->next;
        }
        return mp[head];
    }
};
