class Solution {
public:
    int help(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int op1=help(n-1,dp);
        int op2=help(n-2,dp);
        return dp[n]=op1+op2;   
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return help(n,dp);    
    }
};