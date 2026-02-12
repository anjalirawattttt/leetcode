class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>> & heights,vector<vector<bool>> &visited){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int r = i + rows[k];
            int c = j + cols[k];
            if(r>=0 && c>=0 && r<heights.size() && c<heights[0].size() && !visited[r][c] && heights[r][c]>=heights[i][j]){
                dfs(r,c,heights,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        //pacific top
        for(int j=0;j<n;j++){
            if(!pacific[0][j]){
                dfs(0,j,heights,pacific);
            }
        }
        //pacific left
        for(int i=0;i<m;i++){
            if(!pacific[i][0]){
                dfs(i,0,heights,pacific);
            }
        }
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        //atlantic bottom
        for(int j=0;j<n;j++){
            if(!atlantic[m-1][j]){
                dfs(m-1,j,heights,atlantic);
            }
        }
        //atlantic right
        for(int i=0;i<m;i++){
            if(!atlantic[i][n-1]){
                dfs(i,n-1,heights,atlantic);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;    
    }
};