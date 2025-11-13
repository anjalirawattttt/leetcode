class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp;
        for(int i=0;i<m;i++){
            dp.push_back(vector<int> (i+1,-1));
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0 && j==0){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    int top=INT_MAX,tl=INT_MAX;
                    if(i>0 && j>0)tl=dp[i-1][j-1];
                    if(i>0 && j<i)top=dp[i-1][j];
                    dp[i][j]=triangle[i][j]+min(top,tl);
                }
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<dp[m-1].size();i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};