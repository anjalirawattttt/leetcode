class Solution {
public:
    int help(vector<int>& coins, int amount,int i,vector<vector<int>>& dp){
        if(i==0){
            if(amount%coins[0]==0)return amount / coins[0];
            else return 1e9;
        } 
        if(dp[i][amount]!=-1)return dp[i][amount];
        //pick
        int op1=INT_MAX;
        if(amount>=coins[i])op1=1+help(coins,amount-coins[i],i,dp);
        //not pick
        int op2=help(coins,amount,i-1,dp);
        return dp[i][amount]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=help(coins,amount,n-1,dp); 
        if(ans>=1e9)return -1;
        return ans;   
    }
};