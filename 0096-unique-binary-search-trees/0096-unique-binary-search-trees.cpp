class Solution {
public:
    int numTrees(int n) { 
        if(n<=1)return 1; 
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;i++){
            int ans=0;
            for(int j=1;j<=i;j++){
                int left=dp[j-1];
                int right=dp[i-j];
                ans+=left*right;
            }
            dp[i]=ans;
        } 
        return dp[n];    
    }
};