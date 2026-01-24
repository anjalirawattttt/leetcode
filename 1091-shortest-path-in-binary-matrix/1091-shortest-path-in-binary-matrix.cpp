class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();  
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=true;
        vector<int> rows={0,0,1,-1,1,1,-1,-1};
        vector<int> cols={1,-1,0,0,1,-1,-1,1};
        int moves=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [i,j]=q.front();
                q.pop();
                if(i==n-1 && j==n-1){
                    return moves;
                }
                for(int k=0;k<8;k++){
                    int r=i+rows[k];
                    int c=j+cols[k];
                    if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==0 && !visited[r][c]){
                        visited[r][c]=true;
                        q.push({r,c});
                    }
                }
            }
            moves++;
        }   
        return -1;
    }
};