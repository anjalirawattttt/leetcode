class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
                maxprofit=max(maxprofit,prices[i]-buy);
            
          

        }

        return maxprofit;



    }
};