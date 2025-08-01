class Solution {
public:
    int help(int idx,int pidx,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==nums.size())return 0;
        if(dp[idx][pidx+1]!=-1)return dp[idx][pidx+1]; 

        //take
        int op1=0;
        if(pidx==-1 || nums[idx]>nums[pidx]){
            op1=1+help(idx+1,idx,nums,dp);
        }
        //not take
        int op2= help(idx+1,pidx,nums,dp);
        return dp[idx][pidx+1]=max(op1,op2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return help(0,-1,nums,dp);   
    }
};