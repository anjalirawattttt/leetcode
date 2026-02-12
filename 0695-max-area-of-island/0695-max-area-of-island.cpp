class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        visited[i][j]=true;
        int area=1;
        for(int k=0;k<4;k++){
            int r = i + rows[k];
            int c = j + cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1 && !visited[r][c]){
                area+=dfs(r,c,grid,visited);
            } 
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxArea=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area=dfs(i,j,grid,visited);
                    maxArea=max(maxArea,area);
                }
            }
        }  
        return maxArea;  
    }
};