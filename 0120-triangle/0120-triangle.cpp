class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                //top
                int op1=INT_MAX;
                if(j<i)op1=dp[i-1][j];
                //top left
                int op2=INT_MAX;
                if(j>0)op2=dp[i-1][j-1];
                dp[i][j]=triangle[i][j]+min(op1,op2);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        } 

        int ans=INT_MAX; 
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        } 
        return ans; 
    }
};