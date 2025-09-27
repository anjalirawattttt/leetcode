class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minPriceSoFar=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPriceSoFar=min(minPriceSoFar,prices[i]);
            ans=max(ans,prices[i]-minPriceSoFar);
        }
        return ans;        
    }
};