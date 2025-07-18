class Solution {
public:

    // int help(int n,vector<int>& nums,vector<int>& dp){
    //     if(n==0)return nums[n];
    //     if(n<0)return 0;
    //     if(dp[n]!=-1)return dp[n];
    //     //pick
    //     int op1=nums[n]+help(n-2,nums,dp);
    //     //not pick
    //     int op2=help(n-1,nums,dp);
    //     return dp[n]=max(op1,op2);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<n;i++){
            int op1=INT_MAX;
            if(i==1)op1=nums[i]+neg;
            else op1=nums[i]+dp[i-2];
            int op2=dp[i-1];
            dp[i]=max(op1,op2);
        }
        return dp[n-1];    
    }

};