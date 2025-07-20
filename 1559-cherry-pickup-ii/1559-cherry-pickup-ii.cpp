class Solution {
public:
    // int help(vector<vector<int>>& grid,int i,int j1,int j2,int m,int n,vector<vector<vector<int>>>& dp){
    //     if(j1<0 || j2<0 || j1>=n || j2>=n){
    //         return -1e8;
    //     }
    //     if(i==m-1){
    //         if(j1==j2)return grid[i][j1];
    //         else return grid[i][j1]+grid[i][j2];
    //     }
    //     if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

    //     int maxi=INT_MIN;
    //     for(int j=-1;j<=1;j++){
    //         for(int k=-1;k<=1;k++){
    //             int value;
    //             if(j1==j2)value = grid[i][j1];
    //             else value = grid[i][j1]+grid[i][j2];
    //             value+=help(grid,i+1,j1+j,j2+k,m,n,dp);
    //             maxi=max(maxi,value);
    //         }
    //     }
    //     return dp[i][j1][j2] = maxi;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(n,-1)));
        for(int i=m-1;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    if(i==m-1){
                        if(j1==j2)dp[i][j1][j2]=grid[i][j1];
                        else dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
                    }
                    else{
                        int maxi=INT_MIN;
                        for(int j=-1;j<=1;j++){
                            for(int k=-1;k<=1;k++){
                                int value;
                                if(j1==j2)value = grid[i][j1];
                                else value = grid[i][j1]+grid[i][j2];
                                if(j1+j>=0 && j1+j<n && j2+k>=0 && j2+k<n)value+=dp[i+1][j1+j][j2+k];
                                else value+=-1e8;
                                maxi=max(maxi,value);
                            }
                        }
                        dp[i][j1][j2]=maxi;

                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
};