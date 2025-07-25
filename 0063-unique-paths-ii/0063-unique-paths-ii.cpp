class Solution {
public:
    

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1) {
                dp[i][j]=0;
            }
            else if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                int top=0,left=0;
                if(i>0)top=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=top+left;
            }

            
        }
    }
    return dp[m-1][n-1];
        
    }
};