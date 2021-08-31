class Solution {
public:
    
    // O(N * log N)
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        priority_queue<pair<int, int> > maxHeap;
        unordered_map<int, int> count;
        for(auto &barcode : barcodes) {
            count[barcode]++;
        }
        
        for(auto &[k, v] : count) {
            maxHeap.push({v, k});
        } 
            
        vector<int> result;
        pair<int, int> current, next;
        
        while(!maxHeap.empty()) {
            current = maxHeap.top();
            maxHeap.pop();
            current.first -= 1;
            result.push_back(current.second);
            
            if(!maxHeap.empty()) {
                next = maxHeap.top();
                maxHeap.pop();
                next.first -= 1;
                result.push_back(next.second);
            }
            
            if(current.first > 0) {
                maxHeap.push(current);
            }
            if(next.first > 0) {
                maxHeap.push(next);
            }
        }
        
        return result;
    }
};
