class Solution {
public:
    int help(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        //1
        int op1=help(n-1,dp);
        //2
        int op2=help(n-2,dp);
        return dp[n]=op1+op2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+2,0);
        //n==1 -> 1
        dp[1]=1;
        for(int i=2;i<=n+1;i++){
            //1
            int op1=dp[i-1];
            //2
            int op2=dp[i-2];
            dp[i]=op1+op2;
        }
        
        return dp[n+1];   
    }
};