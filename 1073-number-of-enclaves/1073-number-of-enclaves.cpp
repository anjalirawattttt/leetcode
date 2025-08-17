class Solution {
public:
    void dfs(int i,int j,bool &flag,int &count,vector<vector<bool>> &visited,vector<vector<int>> &grid){
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)flag=true;
        visited[i][j]=true;
        count++;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1 && !visited[r][c])dfs(r,c,flag,count,visited,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    bool flag=false;
                    int count=0;
                    dfs(i,j,flag,count,visited,grid);
                    if(!flag)ans+=count;
                }
            }
        }   
        return ans; 
    }
};