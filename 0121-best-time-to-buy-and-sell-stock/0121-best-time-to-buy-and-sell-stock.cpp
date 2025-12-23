class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mP=0;
        int minPriceTillDay=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minPriceTillDay=min(minPriceTillDay,prices[i]);
            mP=max(mP,prices[i]-minPriceTillDay);
        }
        return mP;    
    }
};