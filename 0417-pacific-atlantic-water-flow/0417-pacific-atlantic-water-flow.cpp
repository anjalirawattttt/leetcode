class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<bool>> &o){
        o[i][j]=true;
        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<heights.size() && c<heights[0].size() && heights[r][c]>=heights[i][j] && !o[r][c]){
                dfs(r,c,heights,o);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> p(m,vector<bool>(n,false));
        vector<vector<bool>> a(m,vector<bool>(n,false));
        
        //first row
        for(int j=0;j<n;j++)dfs(0,j,heights,p);

        //first col
        for(int i=0;i<m;i++)dfs(i,0,heights,p);

        


        //last row
        for(int j=0;j<n;j++)dfs(m-1,j,heights,a);

        //last col
        for(int i=0;i<m;i++)dfs(i,n-1,heights,a);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(p[i][j] && a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};