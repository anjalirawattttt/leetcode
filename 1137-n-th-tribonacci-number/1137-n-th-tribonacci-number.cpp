class Solution {
public:
    int help(int n,vector<int> &dp){
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=help(n-1,dp)+help(n-2,dp)+help(n-3,dp); 
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return help(n,dp);  
    }
};