class StockSpanner {
public:
    
    stack<pair<int, int>> st;
    int index = 0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if(st.empty()){
            st.push({price, index++});
            return 1;
        }
        
        else{
            
            while(!st.empty() && st.top().first <= price){
                st.pop();
            }
            
            int res = st.empty()? index + 1 : index - st.top().second;
            st.push({price, index++});
            return res;
        }
        return -1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */