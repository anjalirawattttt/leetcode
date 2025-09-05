class Solution {
public:
    int help(vector<int>& nums,int i,vector<int>& dp){
        if(i<0)return 0;
        if(i==0)return nums[i];

        if(dp[i]!=-1)return dp[i];
        //rob
        int op1=nums[i]+help(nums,i-2,dp);
        //not rob
        int op2=help(nums,i-1,dp);
        return dp[i]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(nums,n-1,dp);   
    }
};