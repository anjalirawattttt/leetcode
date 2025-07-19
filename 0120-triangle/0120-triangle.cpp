class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp;
        for(int i=0;i<m;i++){
            dp.push_back(vector<int> (i+1,-1));
        }



        for(int i=m-1;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                if(i==m-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};