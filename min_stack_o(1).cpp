class MinStack {
public:
    /** initialize your data structure here. */
    
    /*
    We do 2 * x - minEle to maintain a flag for pop operation
    So in pop operation when we encounter stack top < minEle; it is an indicator that this is the element where the minEle was updated.
    The flag basically acts as a medium to jump to the previous minElement when we pop the current minElement.
    
    
    (2 * currEle - minEle) ==> push 
    (2 * minEle - currEle) ==> pop
    */
    
    
    int minEle = 0;
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minEle = val;
        }
        
        if(val < minEle) {
            s.push(2 * val - minEle);
            minEle = val;
        }
        
        else s.push(val);
    }
    
    void pop() {
        int currEle = s.top();
        if(currEle < minEle) {
            minEle = 2 * minEle - currEle;
        }
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top() < minEle) return minEle;
        else return s.top();
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
