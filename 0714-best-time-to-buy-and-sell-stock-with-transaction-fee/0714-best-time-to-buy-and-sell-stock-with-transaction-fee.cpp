class Solution {
public:
    // int help(int i,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp){
    //     if(i==prices.size())return 0;
    //     int profit=0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     if(buy){
    //         //buy-not buy
    //         profit=max(-prices[i]-fee+help(i+1,0,prices,fee,dp),help(i+1,1,prices,fee,dp));
    //     }
    //     else{
    //         //sell-not sell
    //         profit=max(+prices[i]+help(i+1,1,prices,fee,dp),help(i+1,0,prices,fee,dp));
    //     }
    //     return dp[i][buy]=profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> next(2,0);

        for(int i=n-1;i>=0;i--){
            vector<int> curr(2,0);
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy]=max(-prices[i]-fee+next[0],next[1]);
                }
                else{
                    curr[buy]=max(prices[i]+next[1],next[0]);
                }
            }
            next=curr;
        }
        return next[1];   
    }
};