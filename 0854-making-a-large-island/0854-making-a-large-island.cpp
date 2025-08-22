class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>>& grid,vector<vector<int>> &ids,int id,int &size){
        size++;
        visited[i][j]=true;
        ids[i][j]=id;
        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && !visited[r][c] && grid[r][c]==1){
                dfs(r,c,visited,grid,ids,id,size);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ids(n,vector<int> (n));
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        unordered_map<int,int> m;//id->size
        int id=2;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int size=0;
                    dfs(i,j,visited,grid,ids,id,size);
                    m[id]=size;
                    if(size==n*n)return n*n;
                    id++;
                }
            }
        }  
        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int size=1;
                    unordered_set<int> s;
                    for(int k=0;k<4;k++){
                        int r=i+rows[k];
                        int c=j+cols[k];
                        if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1){
                        if(s.find(ids[r][c])==s.end()){
                            s.insert(ids[r][c]);
                            size+=m[ids[r][c]];
                        }        
                        }
                    }
                    ans=max(ans,size);
                }
            }
        } 
        return ans; 
    }
};