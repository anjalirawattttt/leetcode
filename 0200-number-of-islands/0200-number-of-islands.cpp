class Solution {
public:
    vector<int> rows={0,0,1,-1};
    vector<int> cols={1,-1,0,0};
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<bool>> &visited){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]=='1' && !visited[r][c]){
                dfs(r,c,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    islands++;
                    // cout<<i+1<<" "<<j+1<<endl;
                    dfs(i,j,grid,visited);
                }
            }
        } 
        return islands;   
    }
};