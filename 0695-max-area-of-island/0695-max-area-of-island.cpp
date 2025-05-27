class Solution {
public:
    bool isSafe(int r,int c,int m,int n){
        return r>=0 && c>=0 && r<m && c<n;
    }

    void dfsRec(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int &area,int &ans){
        if(i==grid.size() || j==grid[0].size())return;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(isSafe(r,c,grid.size(),grid[0].size()) && visited[r][c]==false){
                if(grid[r][c]==1){
                    area++;
                    visited[r][c]=true;
                    dfsRec(grid,visited,r,c,area,ans);
                }
            }
        }
        ans=max(ans,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int area;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false && grid[i][j]==1){
                    area=1;
                    visited[i][j]=true;
                    dfsRec(grid,visited,i,j,area,ans);
                }
            }
        }
        return ans;    
    }
};