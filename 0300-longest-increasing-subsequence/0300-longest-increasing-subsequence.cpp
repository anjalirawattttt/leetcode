class Solution {
public:
    int help(int i,int prev,vector<int>& nums,vector<vector<int>> &dp){
        if(i<0)return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        //take
        int op1=0;
        if(prev==nums.size() || nums[i]<nums[prev]){
            op1=1+help(i-1,i,nums,dp);
        }
        //not take
        int op2=help(i-1,prev,nums,dp);
        return dp[i][prev]=max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        //tabulation
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // for(int prev=0;prev<n+1;prev++)dp[0][prev]=0;
        //use i-1 for index;
        for(int i=1;i<n+1;i++){
            for(int prev=0;prev<n+1;prev++){
                //take
                int op1=0;
                if(prev==n || nums[i-1]<nums[prev]){
                    op1=1 + dp[i-1][i-1] ; 
                    // help(i-1,i,nums,dp);
                }
                //not take
                int op2=dp[i-1][prev];
                //help(i-1,prev,nums,dp);
                dp[i][prev]=max(op1,op2);   
            }
        }
        return dp[n][n]; 
    }
};