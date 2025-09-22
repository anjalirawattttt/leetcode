class Solution {
public:
    int help(int i,vector<int>& nums,int j,vector<int>& dp){
        if(i<j)return 0;
        if(dp[i]!=-1)return dp[i];
        //take
        int op1=nums[i]+help(i-2,nums,j,dp);
        //not take
        int op2=help(i-1,nums,j,dp);
        return dp[i]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int op1=nums[n-1]+help(n-3,nums,1,dp1);
        int op2=help(n-2,nums,0,dp2);
        return max(op1,op2);    
    }
};