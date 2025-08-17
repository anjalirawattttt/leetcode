class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        } 

        int time=0;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};

        while(!q.empty()){
            int size=q.size();
            bool rot=false;
            while(size--){
                auto [r,c]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+rows[k];
                    int nc=c+cols[k];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        rot=true;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            if(rot)time++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;
    }
};