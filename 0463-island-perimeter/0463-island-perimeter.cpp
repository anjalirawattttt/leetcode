class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited,int &ans){
        visited[i][j]=true;
        int peri=4;
        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                peri--;
                if(!visited[r][c]){
                    bfs(r,c,grid,visited,ans);
                }
            }
        }
        ans+=peri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    // bfs(i,j,grid,visited,ans);
                    // break;
                    int peri=4;
                    vector<int> rows={0,0,1,-1};
                    vector<int> cols={1,-1,0,0};
                    for(int k=0;k<4;k++){
                        int r=i+rows[k];
                        int c=j+cols[k];
                        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                            peri--;
                            
                        }
                    }
                    ans+=peri;
                }
            }
        }
        return ans;
    }
};