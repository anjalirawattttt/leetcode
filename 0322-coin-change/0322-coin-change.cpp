class Solution {
public:
    int help(vector<int> &coins,int amount,int i,vector<vector<int>> &dp){
        if(amount==0)return 0;
        if(i<0){
            return 1e6;
        }
        if(dp[amount][i]!=-1)return dp[amount][i];
        int op1=INT_MAX;
        if(amount>=coins[i]){
            op1= 1 + help(coins,amount-coins[i],i,dp);
        }

        int op2=help(coins,amount,i-1,dp);
        return dp[amount][i]=min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        int ans=help(coins,amount,n-1,dp);
        return ans>=1e6?-1:ans;  
    }
};