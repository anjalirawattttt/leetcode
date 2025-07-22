class Solution {
public:
    int help(int i,int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[0]==0)return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        //pick
        int op1=0;
        if(coins[i]<=amount)op1=help(i,amount-coins[i],coins,dp);
        //not pick
        int op2=help(i-1,amount,coins,dp);
        return dp[i][amount]=op1+op2;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return help(n-1,amount,coins,dp);   
    }
};