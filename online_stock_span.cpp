class StockSpanner {
public:
    stack<pair<int, int>> st; //{price, count/index}
    
    StockSpanner() {
    }
    
    int next(int price) {
        
    
        int count = 1;    
        while(not st.empty() and st.top().first <= price) {
            count += st.top().second;
            st.pop();
        }
        
        st.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
