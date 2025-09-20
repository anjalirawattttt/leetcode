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
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return help(n-1,n,nums,dp); 
    }
};