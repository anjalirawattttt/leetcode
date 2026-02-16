class Solution {
public:

    bool check(int i,int j,int threshold,vector<vector<int>> &heights,vector<vector<bool>> &visited){
        if(i==heights.size()-1 && j==heights[0].size()-1)return true;

        bool poss=false;
        visited[i][j]=true;
        //top
        if(i>0 && abs(heights[i][j]-heights[i-1][j])<=threshold && !visited[i-1][j] ){
            poss = poss | check(i-1,j,threshold,heights,visited);
        }
        //bottom
        if(i<heights.size()-1 && abs(heights[i][j]-heights[i+1][j])<=threshold && !visited[i+1][j] ){
            poss = poss | check(i+1,j,threshold,heights,visited);
        }
        //left
        if(j>0 && abs(heights[i][j]-heights[i][j-1])<=threshold && !visited[i][j-1] ){
            poss = poss | check(i,j-1,threshold,heights,visited);
        }
        //right
        if(j<heights[0].size()-1 && abs(heights[i][j]-heights[i][j+1])<=threshold && !visited[i][j+1] ){
            poss = poss | check(i,j+1,threshold,heights,visited);
        }
        // visited[i][j]=false;
        return poss;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        int minEle=INT_MAX;
        int maxEle=INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                minEle=min(minEle,heights[i][j]);
                maxEle=max(maxEle,heights[i][j]);     
            }
        }

        int l=0,r=maxEle-minEle;
        int ans=INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            if( check(0,0,mid,heights,visited) ){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};