class Solution {
public:
    // int help(vector<vector<int>> &grid,int i,int j,vector<vector<int>>& dp){
    //     if(i<0 || j<0)return 1e7;
    //     if(i==0 && j==0)return grid[0][0];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     //top
    //     int op1=grid[i][j]+help(grid,i-1,j,dp);
    //     //left
    //     int op2=grid[i][j]+help(grid,i,j-1,dp);
    //     return dp[i][j]=min(op1,op2);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prev (n+1,1e7);

        for(int i=1;i<=m;i++){
            vector<int> curr(n+1,1e7);
            if(i==1)curr[1]=grid[0][0];
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)continue;
                //top
                int op1=grid[i-1][j-1]+prev[j];
                //left
                int op2=grid[i-1][j-1]+curr[j-1];
                curr[j]=min(op1,op2);   
            }
            prev=curr;
        }
        return prev[n];    
    }
};