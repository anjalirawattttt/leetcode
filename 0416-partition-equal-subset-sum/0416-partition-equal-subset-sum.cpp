class Solution {
public:
    bool help(vector<int> &nums,int i,int sum,vector<vector<int>> &dp){
        if(sum==0)return true;
        if(sum<0)return false;
        if(i>=nums.size())return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        //take
        bool op1=help(nums,i+1,sum-nums[i],dp);
        //not take
        bool op2=help(nums,i+1,sum,dp);
        return dp[i][sum]=op1|op2;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return false;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }  
        if(sum%2==1)return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return help(nums,0,sum/2,dp);  
    }
};