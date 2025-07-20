class Solution {
public:
    int help(vector<vector<int>>& grid,int r1,int r2,int c1,int n,vector<vector<vector<int>>>& dp){
        int c2=r1+c1-r2;
        if(r1>=n || r2>=n || c1>=n ||c2>=n)return -1e8;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)return -1e8;
        if(r1==n-1 && c1==n-1 && r2==n-1 && c2==n-1)return grid[n-1][n-1];

        if(dp[r1][r2][c1]!=-1)return dp[r1][r2][c1];
        int cherries=0;
        if(r1==r2 && c1==c2)cherries=grid[r1][c1];
        else cherries=grid[r1][c1]+grid[r2][c2];
        
        int temp=max({
            help(grid,r1+1,r2+1,c1,n,dp),
            help(grid,r1,r2,c1+1,n,dp),
            help(grid,r1+1,r2,c1,n,dp),
            help(grid,r1,r2+1,c1+1,n,dp)
        });

        return dp[r1][r2][c1]=cherries+temp;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,help(grid,0,0,0,n,dp));   
    }
};