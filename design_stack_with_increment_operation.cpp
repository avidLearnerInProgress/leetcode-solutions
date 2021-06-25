class CustomStack {
public:
    int max;
    vector<int> v;
    
    CustomStack(int maxSize) {
        max = maxSize;
    }
    
    void push(int x) {
        if(v.size() < max) v.push_back(x);
    }
    
    int pop() {
        if(v.size() == 0) return -1;
        int result = v.back();
        v.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        if(v.size() < k) k = v.size();
        
        for(int i = 0; i < k; i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
