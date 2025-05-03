class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        int buy=prices[0];
        int sell;
        for(int i=0;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            if(prices[i]>buy){
                sell=prices[i];
                maxprofit=max(maxprofit,sell-buy);
            }

        }

        return maxprofit;



    }
};