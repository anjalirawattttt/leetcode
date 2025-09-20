class Solution {
public:
    int help(int i,vector<int>& coins,int amount,vector<vector<int>> &dp){
        if(amount==0)return 0;
        if(i<0)return 1e7;
        if(dp[i][amount]!=-1)return dp[i][amount];
        //take
        int op1=1e7;
        if(amount>=coins[i])op1=1+help(i,coins,amount-coins[i],dp);
        //not take
        int op2=help(i-1,coins,amount,dp);
        return dp[i][amount]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        //base case i=0
        for(int a=0;a<=amount;a++)dp[0][a]=1e7;
        //base case amount ==0 =>0
        //i-1
        for(int i=1;i<=n;i++){
            for(int a=1;a<=amount;a++){
                //take
                int op1=1e7;
                if(a>=coins[i-1])op1=1+dp[i][a-coins[i-1]];
                //not take
                int op2=dp[i-1][a];
                dp[i][a]=min(op1,op2);    
            }
        }

        int ans=dp[n][amount];
        return ans>=1e7?-1:ans;    
    }
};