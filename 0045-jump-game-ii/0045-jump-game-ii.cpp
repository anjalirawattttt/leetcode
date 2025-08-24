class Solution {
public:

    int help(int i,vector<int>& nums,vector<int> &dp){
        int n=nums.size();
        if(i==n-1)return 0;

        if(dp[i]!=-1)return dp[i];

        int jumps=1e8;
        for(int j=i+1;j<=min(i+nums[i],n-1);j++){
            jumps=min(jumps,1+help(j,nums,dp));
        }  
        return dp[i]=jumps;
    }
   

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(0,nums,dp);    
    }
};