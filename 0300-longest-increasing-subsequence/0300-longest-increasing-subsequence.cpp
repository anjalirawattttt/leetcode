class Solution {
public:
    int help(int prev,int i,vector<int>& nums,vector<vector<int>> &dp){
        if(i<0)return 0;
        if(dp[prev][i]!=-1)return dp[prev][i];
        //take
        int op1=0;
        if(prev==nums.size() || nums[i]<nums[prev]){
            op1=1+help(i,i-1,nums,dp);
        }
        //not take
        int op2=help(prev,i-1,nums,dp);
        return dp[prev][i]=max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        //tabulation
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return help(n,n-1,nums,dp);   
    }
};