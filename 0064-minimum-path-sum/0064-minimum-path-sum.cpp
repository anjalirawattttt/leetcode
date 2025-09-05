class Solution {
public:
    int help(vector<vector<int>> &grid,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0)return 1e7;
        if(i==0 && j==0)return grid[0][0];
        if(dp[i][j]!=-1)return dp[i][j];
        //top
        int op1=grid[i][j]+help(grid,i-1,j,dp);
        //left
        int op2=grid[i][j]+help(grid,i,j-1,dp);
        return dp[i][j]=min(op1,op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return help(grid,m-1,n-1,dp);    
    }
};