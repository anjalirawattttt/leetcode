class Solution {
public:
    bool help(int i,vector<int>& nums,vector<int> &dp){
        int n=nums.size();
        if(i==n-1)return true;

        if(dp[i]!=-1)return dp[i];

        bool ans=false;
        for(int j=i+1;j<=min(i+nums[i],n-1);j++){
            ans = ans || help(j,nums,dp);
        }  
        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(0,nums,dp);
    }
};