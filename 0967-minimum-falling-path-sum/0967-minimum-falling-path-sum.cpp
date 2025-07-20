class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n,-1);
        int var=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[j]=matrix[i][j];
                }
                else{
                    int top=INT_MAX,tr=INT_MAX,tl=INT_MAX;
                    if(i>0)top=dp[j];
                    if(i>0 && j<n-1)tr=dp[j+1];
                    if(i>0 && j>0)tl=var;
                    var=dp[j];
                    dp[j] = matrix[i][j]+min(top,min(tl,tr));

                }
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i]);
        }
        return ans;
    }
};