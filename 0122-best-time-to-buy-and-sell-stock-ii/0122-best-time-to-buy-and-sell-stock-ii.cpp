class Solution {
public:
    int help(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size())return 0;
        long profit=0;
        if(dp[buy][i]!=-1)return dp[buy][i];
        if(buy){
            //buy-not buy
            profit=max(-prices[i]+help(i+1,0,prices,dp),help(i+1,1,prices,dp));
        }
        else{
            //sell-not sell
            profit=max(+prices[i]+help(i+1,1,prices,dp),help(i+1,0,prices,dp));
        }
        return dp[buy][i]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(n,-1));

        return help(0,true,prices,dp);    
    }
};