class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0],profit=0;
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-mini);
            mini=min(mini,prices[i]);
        } 
        return profit; 
    }
};