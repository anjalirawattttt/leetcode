class StockSpanner {
    stack<pair<int,int>> s;//idx,element
    int idx;
public:
    StockSpanner() {
        idx=0;
    }
    
    int next(int price) {
        while(!s.empty() && s.top().second<=price)s.pop();
        int ans=s.empty() ? idx+1 : idx-s.top().first;
        s.push({idx,price});
        idx++;    
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */