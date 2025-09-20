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
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=help(n-1,coins,amount,dp);
        return ans>=1e7?-1:ans;    
    }
};