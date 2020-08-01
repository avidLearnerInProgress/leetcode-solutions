class MinStack {
public:
    /** initialize your data structure here. */
    stack<long double> s;
    long min;
    
    MinStack() {
        
    }
    
    void push(long double x) {
        if(s.empty()) { //if stack is empty just push and set it as min
            s.push(x);
            min = x;
        }    
        else{
            if(x < min) { //if current value is less than current min, create flag in stack as 2 * x - min which will allow to traverse amongst next min while popping
                s.push(2 * x - min);
                min = x;
            }
            else
                s.push(x); //just push current x
        }
    }
    
    void pop() {
        if(!s.empty()){ //if stack is non empty
            if(s.top() < min) { //if current top is less than min, this indicates that the top is flag. Which means that we update the min to next closest min and then pop the current top
                min = 2 * min - s.top();
                s.pop();
            }
            else { //else just pop
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.top() < min) { //if top is less than min 
            return min;
        }
        else return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
