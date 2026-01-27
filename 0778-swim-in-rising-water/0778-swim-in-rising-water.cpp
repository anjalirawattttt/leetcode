class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited,int ans){
        if(i==grid.size()-1 && j==grid.size()-1){
            return max(ans,grid[i][j]);
        }
        int result=INT_MAX;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid.size() && !visited[r][c]){
                result=min(result,dfs(r,c,grid,visited,max(ans,grid[r][c])));
            }
        }
        visited[i][j]=false;
        return result;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=grid[0][0];
        using T=pair<int,pair<int,int>>;
        priority_queue < T , vector<T> , greater<T> > pq;
        pq.push({dp[0][0],{0,0}});
        while(!pq.empty()){
            auto [d,it]=pq.top();
            pq.pop();
            int i=it.first;
            int j=it.second;
            if(d>dp[i][j])continue;
            for(int k=0;k<4;k++){
                int r=i+rows[k];
                int c=j+cols[k];
                if(r>=0 && c>=0 && r<grid.size() && c<grid.size() && dp[r][c]>max(grid[r][c],dp[i][j])){
                    dp[r][c]=max(grid[r][c],dp[i][j]);
                    pq.push({dp[r][c],{r,c}});
                }
            }
        }
        return dp[n-1][n-1];
    }
};