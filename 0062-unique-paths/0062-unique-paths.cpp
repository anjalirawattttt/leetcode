class Solution {
public:
    int help(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        //top
        int op1=help(i-1,j,dp);
        //left
        int op2=help(i,j-1,dp);
        return dp[i][j]=op1+op2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //base case i->0 || j->0 ==> dp->0
        dp[1][1]=1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)continue;
                //top
                int op1=dp[i-1][j];
                //left
                int op2=dp[i][j-1];
                dp[i][j]=op1+op2;
            }
        }


        return dp[m][n];    
    }
};