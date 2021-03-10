class FrontMiddleBackQueue {
public:
    vector<int> que; // vector name given que bc it represent queue
    FrontMiddleBackQueue() {
        //do nothing
    }
    
    void pushFront(int val) {
        que.insert(que.begin(),val );//insert at begin with using insert function 
    }
    
    void pushMiddle(int val) {
        que.insert(que.begin()+(que.size()/2),val); // middleposition = que.begin()+(que.size()/2);
    }
    
    void pushBack(int val) {
        que.push_back(val); //back insertion 
    }
    
    int popFront() {
        if(que.size()>0){
            int temp = que[0];
            que.erase(que.begin()); // pop_front()
            return temp;
        }
        return -1;
    }
    
    int popMiddle() {
        if(que.size()>0){
            if(que.size()%2){ // poping middle if que length is odd
                int temp = que[ceil(que.size()/2)];
                que.erase(que.begin()+ceil(que.size()/2));
                return temp;
            }
            else{ // if queue length is even
                int temp = que[que.size()/2 -1];
                que.erase(que.begin()+que.size()/2 -1);
                return temp; 
            }
        }
        return -1;
        
    }
    
    int popBack() {
        if(que.size()>0){
            int temp = que[que.size()-1];
            que.erase(que.begin()+que.size()-1); // poping back element 
            return temp;
        }
        return -1;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
