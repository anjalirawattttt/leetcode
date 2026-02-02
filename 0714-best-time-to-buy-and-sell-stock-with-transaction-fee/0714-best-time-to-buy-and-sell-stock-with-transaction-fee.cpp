class Solution {
public:
    int help(int buy,int i,vector<int> &prices,vector<vector<int>>& dp,int fee){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[buy][i]!=-1)return dp[buy][i];
        int profit=0;
        if(buy){
            //buy
             profit = max(profit,-prices[i]+help(0,i+1,prices,dp,fee) );
            //not buy
             profit = max(profit,help(buy,i+1,prices,dp,fee));
        }
        else{
            //sell
             profit = max(profit,prices[i]-fee+help(1,i+1,prices,dp,fee));
            //not sell
             profit = max(profit,help(buy,i+1,prices,dp,fee));
        }
        return dp[buy][i]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(n,-1));
        return help(1,0,prices,dp,fee);    
    }
};