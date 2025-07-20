class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else{
                    int top=INT_MAX,tl=INT_MAX,tr=INT_MAX;
                    if(i>0)top=dp[i-1][j];
                    if(i>0 && j>0)tl=dp[i-1][j-1];
                    if(i>0 && j<n-1)tr=dp[i-1][j+1];
                    dp[i][j] = matrix[i][j]+min(top,min(tl,tr));  
                }
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};