class Solution {
public:
    int help(int buy,int i,vector<int> &prices,vector<vector<int>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[buy][i]!=-1)return dp[buy][i];
        int profit=0;
        if(buy){
            //buy
            profit = max(profit, -prices[i]+help(0,i+1,prices,dp) );
            //not buy
            profit = max(profit, help(buy,i+1,prices,dp) );
        }
        else{
            //sell
            profit = max(profit, prices[i]+help(1,i+1,prices,dp) );
            //not sell
            profit = max(profit, help(buy,i+1,prices,dp) );
        }
        return dp[buy][i]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();   
        vector<vector<int>> dp(2,vector<int>(n,-1));     
        return help(1,0,prices,dp);   
    }
};