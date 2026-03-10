class Solution {
public:
    int help(int n,vector<int> &dp){
        if(n==0)return 1;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=1;
        for(int i=2;i<=n;i++){
            ans=max(ans,i*help(n-i,dp));
        }
        return dp[n]=ans;    
    }

    int integerBreak(int n) {

        vector<int> dp(n+1,-1);
        int ans=1;
        for(int i=2;n-i>=1;i++){
            ans=max(ans,i*help(n-i,dp));
        }
        return ans;
    }
};