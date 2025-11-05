class Solution {
public:
    int help(vector<int>& nums,int i,vector<int> &dp){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=nums[i]+help(nums,i-2,dp);
        int op2=help(nums,i-1,dp);
        return dp[i]=max(op1,op2);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            int idx=i-1;
            int op1=nums[idx]+dp[i-2];
            int op2=dp[i-1];
            dp[i]=max(op1,op2);
        }

        return dp[n];    
    }
};