class Solution {
public:
vector<int> rows={1,-1,0,0};
vector<int> cols={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>> &grid){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                dfs(r,c,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid);
            }
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
        }   

        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
            if(grid[m-1][j]==1){
                dfs(m-1,j,grid);
            }
        } 
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }   
        return ans; 
    }
};