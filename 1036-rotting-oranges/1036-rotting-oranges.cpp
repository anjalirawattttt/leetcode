class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0,time=0;
        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }

        while(!q.empty() && fresh>0){
            int size=q.size();
            
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int r=x+rows[i];
                    int c=y+cols[i];
                    if(r>=0 && c>=0 && r<m && c<n && grid[r][c]==1){
                        fresh--;
                        grid[r][c]=2;
                        q.push({r,c});
                    }
                }
            }
            time++;
        }

        return (fresh==0)?time:-1;

    }
};