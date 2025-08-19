class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        vector<int> rows={1,1,1,-1,-1,-1,0,0};
        vector<int> cols={-1,0,1,-1,0,1,-1,1};

        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            int d=grid[i][j];
            if(i==n-1 && j==n-1)return d;
            for(int k=0;k<8;k++){
                int r=i+rows[k];
                int c=j+cols[k];
                if(r>=0 && c>=0 && r<n && c<n  && grid[r][c]==0){
                    grid[r][c]=d+1;
                    q.push({r,c});
                }
            }
        }


        return -1;    
    }
};