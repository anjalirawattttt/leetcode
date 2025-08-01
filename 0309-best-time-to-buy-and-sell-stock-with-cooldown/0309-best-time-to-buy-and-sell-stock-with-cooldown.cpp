class Solution {
public:
    // int help(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
    //     if(i>=prices.size())return 0;
    //     int profit=0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     if(buy){
    //         //buy-not buy
    //         profit=max(-prices[i]+help(i+1,0,prices,dp),help(i+1,1,prices,dp));
    //     }
    //     else{
    //         //sell-not sell
    //         profit=max(+prices[i]+help(i+2,1,prices,dp),help(i+1,0,prices,dp));
    //     }
    //     return dp[i][buy]=profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> nextnext(2,0);
        vector<int> next(2,0);
        for(int i=n-1;i>=0;i--){
            vector<int> curr(2,0);
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    //buy-not buy
                    curr[buy]=max(-prices[i]+next[0],next[1]);
                }
                else{
                    //sell-not sell
                    curr[buy]=max(prices[i]+nextnext[1],next[0]);
                } 
            }
            nextnext=next;
            next=curr;

        }
        return next[1];
        
    }
};