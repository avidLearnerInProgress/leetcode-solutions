class Solution {
public:
    
    /*
    There should be only 1 root node (node without any parent nodes). Reason - More than one root node results in more than 1 tree which negative the requirements of the question.
    
    Should satisfy requirements of a tree -
        2.a. Every Node should have only one parent.
        2.b. There shouldn't be any cycles

    */
     bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
         
        vector<int> parents (n, 0);
        queue<int> nodes;
        unordered_set<int> seen;
		
         // 1st step - Find parent and use that to find the root. The node without any parents will be the root.
        for (int i=0; i<n; ++i) {
            if (leftChild[i] != -1)
                ++parents[leftChild[i]];
            if (rightChild[i] != -1)
                ++parents[rightChild[i]];
        }
        for (int i=0; i<n; ++i) {
            if (parents[i] == 0)
                nodes.push(i);
            
			// If is any node with more than 1 parent then that **negates 2.a**
            else if (parents[i] > 1)
                return false;
            
        }
		// If there is no root or more than 1 root then it **negates 1st** point.
        if (nodes.size() != 1)
            return false;
			
		
        while(!nodes.empty()) {
            int node = nodes.front(); 
            nodes.pop();
            if (node == -1)
                continue;
			// If TRUE, then there is a cycle - negates 2.b
            if (seen.count(node) != 0)
                return false;
            seen.insert(node);
            nodes.push(leftChild[node]);
            nodes.push(rightChild[node]);
        }
        
         // checks if all the nodes are visited.
        return (seen.size() == n);
    }
};
