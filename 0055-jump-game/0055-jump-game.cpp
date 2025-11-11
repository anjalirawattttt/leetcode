class Solution {
public:
    // bool help(int idx,vector<int> &nums,vector<int> &dp){
    //     if(idx==nums.size()-1)return true;
    //     if(dp[idx]!=-1)return dp[idx];
    //     for(int i=1;i<=nums[idx];i++){
    //         if(help(idx+i,nums,dp))return true;
    //     }
    //     return dp[idx]=false;
    // }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,false);
        dp[n-1]=true;

        for(int idx=n-2;idx>=0;idx--){
            for(int i=1;i<=nums[idx];i++){
                if(idx+i<n && dp[idx+i])dp[idx]=true;
            }
        }

        return dp[0];    
    }
};