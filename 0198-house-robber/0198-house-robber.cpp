class Solution {
public:
    int help(int i,vector<int>& nums,vector<int> &dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        //take
        int op1=nums[i]+help(i-2,nums,dp);
        //not take
        int op2=help(i-1,nums,dp);
        return dp[i]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for(int i=2;i<=n+1;i++){
            //take
            int op1=nums[i-2]+dp[i-2];
            //not take
            int op2=dp[i-1];
            dp[i]=max(op1,op2);
        }
        return dp[n+1];    
    }
};