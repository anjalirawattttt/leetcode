class Solution {
public:
    bool help(int i,vector<int>& nums,int sum,vector<vector<int>> &dp){
        if(sum==0)return true;
        if(i<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool op1=false;
        if(sum>=nums[i]){
            op1=help(i-1,nums,sum-nums[i],dp);
        }
        bool op2=help(i-1,nums,sum,dp);
        return dp[i][sum]=op1|op2;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        } 

        if(sum%2==1)return false;

        sum=sum/2;

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return help(n-1,nums,sum,dp);   

    }
};