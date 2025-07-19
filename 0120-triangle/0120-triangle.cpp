class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<int> dp(n,-1);



        for(int i=m-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                if(i==m-1){
                    dp[j]=triangle[i][j];
                }
                else{
                    dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
                }
            }
        }

        return dp[0];
    }
};