class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dist){
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<mat.size() && c<mat[0].size() && mat[r][c]==1 && dist[r][c]>dist[i][j]+1){
                dist[r][c]=(dist[i][j]+1);
                dfs(r,c,mat,dist);
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    dfs(i,j,mat,dist);
                }
            }
        }
        return dist;
        
    }
};