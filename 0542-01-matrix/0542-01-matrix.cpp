class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        // multi source bfs
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});    
                }
            }
        }

        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=i+rows[k];
                int nc=j+cols[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc]= dist[i][j]+1;
                    q.push({nr,nc});
                }
            }
        }  
        return dist;
    }
};