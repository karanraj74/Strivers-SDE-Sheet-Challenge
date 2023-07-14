class StockSpanner {
public:
    stack<pair<int,int>>st;
    int count=0;
    StockSpanner() {

    }
    
    int next(int price) {
        
        count++;
        
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(st.empty()){
            st.push({price,count});
            return count;
        }
        else{
            int k=count-st.top().second;
            st.push({price,count});
            return k;
        }
         
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
