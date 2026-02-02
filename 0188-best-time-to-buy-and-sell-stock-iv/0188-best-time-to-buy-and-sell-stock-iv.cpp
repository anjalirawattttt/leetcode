class Solution {
public:
    int help(int buy,int i,int totalSell,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(totalSell==0)return 0;
        if(dp[buy][i][totalSell]!=-1)return dp[buy][i][totalSell];
        int profit=0;
        if(buy){
            //buy
            profit = max(profit, -prices[i]+help(0,i+1,totalSell,prices,dp) );
            //not buy
            profit = max(profit, help(buy,i+1,totalSell,prices,dp) );
        }
        else{
            //sell
            int s = prices[i]+help(1,i+1,totalSell-1,prices,dp);
            profit = max(profit,s);
            //not sell
            int ns = help(buy,i+1,totalSell,prices,dp) ;
            profit = max(profit,ns);
        }
        return dp[buy][i][totalSell]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();   
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(k+1,-1)));     
        return help(1,0,k,prices,dp);       
    }
};