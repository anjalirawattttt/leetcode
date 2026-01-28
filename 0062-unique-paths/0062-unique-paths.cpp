class Solution {
public:
    int uniquePaths(int m, int n) {
        //top left
        vector<vector<int>> dp(m,vector<int>(n,0));
        //first row
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        //first column
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //top
                int op1=dp[i-1][j];
                //left
                int op2=dp[i][j-1];
                dp[i][j]=op1+op2;
            }
        }  
        return dp[m-1][n-1];  
    }
};