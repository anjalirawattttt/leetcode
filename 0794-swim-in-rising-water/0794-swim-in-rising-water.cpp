class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> height(n,vector<int>(n,INT_MAX));

        priority_queue<tuple<int,int,int>> pq;//height , i , j
        pq.push({grid[0][0],0,0});
        height[0][0]=grid[0][0];

        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};


        while(!pq.empty()){
            auto [currHeight,i,j]=pq.top();
            pq.pop();
            if(currHeight>height[i][j])continue;
            for(int k=0;k<4;k++){
                int r=i+rows[k];
                int c=j+cols[k];
                if(r>=0 && c>=0 && r<n && c<n ){
                    int newHeight=max(currHeight,grid[r][c]);
                    if(newHeight<height[r][c]){
                        height[r][c]=newHeight;
                        pq.push({newHeight,r,c});
                    }
                }
            }

        }
        return height[n-1][n-1];

    }
};