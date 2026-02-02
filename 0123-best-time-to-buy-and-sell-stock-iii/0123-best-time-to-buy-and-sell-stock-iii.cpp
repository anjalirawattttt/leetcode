class Solution {
public:
    int help(int buy,int i,int totalSell,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(totalSell==2)return 0;
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
            int s = prices[i]+help(1,i+1,totalSell+1,prices,dp);
            profit = max(profit,s);
            //not sell
            int ns = help(buy,i+1,totalSell,prices,dp) ;
            profit = max(profit,ns);
        }
        return dp[buy][i][totalSell]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();   
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(3,0)));  

        // if(i==n){
        //     return 0;
        // }
        // if(totalSell==2)return 0;  

    
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int totalSell=1;totalSell>=0;totalSell--){
                    int profit=0;
                    if(buy){
                        //buy
                        profit = max(profit, -prices[i]+dp[0][i+1][totalSell]);
                        //not buy
                        profit = max(profit, dp[buy][i+1][totalSell] );
                    }
                    else{
                        //sell
                        int s =  prices[i]+dp[1][i+1][totalSell+1];
                        profit = max(profit,s);
                        //not sell
                        int ns = dp[buy][i+1][totalSell] ;
                        profit = max(profit,ns);
                    }
                    dp[buy][i][totalSell] = profit ;
                }
            }
        }



        return dp[1][0][0];    
    }
};