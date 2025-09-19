class Solution {
public:
    void help(int i,int j,vector<vector<bool>> &visited,vector<vector<int>>& heights){
        visited[i][j]=true;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<heights.size() && c<heights[0].size() && !visited[r][c] && heights[r][c]>=heights[i][j]){
                help(r,c,visited,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> vp(m,vector<bool>(n,false));
        vector<vector<bool>> va(m,vector<bool>(n,false));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            if(!vp[i][0])help(i,0,vp,heights);
            if(!va[i][n-1])help(i,n-1,va,heights);
        }
        for(int j=0;j<n;j++){
            if(!vp[0][j])help(0,j,vp,heights);
            if(!va[m-1][j])help(m-1,j,va,heights);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vp[i][j] && va[i][j])ans.push_back({i,j});
            }
        }
        return ans;          
    }
};