class Solution {
public:
    // bool help(vector<int>& nums,int n,int target,vector<vector<int>>& dp){
    //     if(target==0)return true;
    //     if(n==0)return nums[n]==target;
    //     if(dp[n][target]!=-1)return dp[n][target];
    //     //pick
    //     bool op1=false;
    //     if(target>=nums[n])op1=help(nums,n-1,target-nums[n],dp);
    //     //not pick
    //     bool op2=help(nums,n-1,target,dp);
    //     return dp[n][target]=op1|op2;

    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        } 
        if(sum % 2 != 0) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        //target==0
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        //n==0
        if(nums[0]<=target)dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                    //pick
                    bool op1=false;
                    if(t>=nums[i])op1=dp[i-1][t-nums[i]];
                    //not pick
                    bool op2=dp[i-1][t];
                    dp[i][t]=op1|op2;   
            }
        }

        return dp[n-1][target];
    }
};