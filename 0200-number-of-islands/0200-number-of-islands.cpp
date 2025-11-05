class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<bool>> &visited){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1' && !visited[r][c]){
                bfs(r,c,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        } 
        return count;   
    }
};