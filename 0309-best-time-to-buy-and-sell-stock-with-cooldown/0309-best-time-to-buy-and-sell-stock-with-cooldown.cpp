class Solution {
public:
    int help(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size())return 0;
        int profit=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            //buy-not buy
            profit=max(-prices[i]+help(i+1,0,prices,dp),help(i+1,1,prices,dp));
        }
        else{
            //sell-not sell
            profit=max(+prices[i]+help(i+2,1,prices,dp),help(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return help(0,1,prices,dp);
        
    }
};