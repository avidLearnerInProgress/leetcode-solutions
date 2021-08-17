class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int> > Q;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto num : nums) {
            Q.push(num);
            if(Q.size() > k) Q.pop(); //only keep k elements in the Queue
        }
    }
    
    int add(int val) {
        Q.push(val);
        if(Q.size() > size) Q.pop();
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
