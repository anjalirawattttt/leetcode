class Solution {
public:
    int help(int prev,int i,vector<int>& nums,vector<vector<int>> &dp){
        if(i>=nums.size())return 0;
        if(dp[prev+1][i]!=-1)return dp[prev+1][i];
        //take
        int op1=0;
        if(prev==-1 || nums[i]>nums[prev]){
            op1=1+help(i,i+1,nums,dp);
        }
        //not take
        int op2=help(prev,i+1,nums,dp);
        return dp[prev+1][i]=max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return help(-1,0,nums,dp);   
    }
};