class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();        
        int ans=0;
        int buyPrice=INT_MAX;
        for(int i=0;i<n;i++){
            buyPrice=min(buyPrice,prices[i]);
            if(buyPrice<prices[i]){
                ans+=prices[i]-buyPrice;
                buyPrice=prices[i];
            }
        }
        return ans;    
    }
};