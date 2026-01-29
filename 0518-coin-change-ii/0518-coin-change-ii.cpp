class Solution {
public:
    int help(int i,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(amount==0)return 1;
        if(i<0)return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        //take
        int op1=0;
        if(amount>=coins[i]){
            op1=help(i,coins,amount-coins[i],dp);
        }
        //not take
        int op2=help(i-1,coins,amount,dp);
        return dp[i][amount]=  op1+op2;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return help(n-1,coins,amount,dp);
    }
};