class Solution {
public:
    int help(vector<int> &nums,int n,int prev,vector<vector<int>> &dp){
        if(n<0)return 0;
        if(dp[n][prev]!=-1)return dp[n][prev];
        int op=0;
        for(int i=n;i>=0;i--){
            if(prev==nums.size() || nums[i]<nums[prev])op=max(op,1+help(nums,i-1,i,dp));
        }
        return dp[n][prev]=op;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return help(nums,n-1,n,dp);    
    }
};