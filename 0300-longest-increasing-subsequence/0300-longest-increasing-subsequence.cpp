class Solution {
public:
    int help(int prev,int i,vector<int> &nums,vector<vector<int>>& dp){
        if(i<0)return 0;
        if(dp[prev+1][i]!=-1)return dp[prev+1][i];
        if(prev==-1 || nums[prev]>nums[i]){
            //take
            int op1=1+help(i,i-1,nums,dp);
            //not take
            int op2=help(prev,i-1,nums,dp);
            return dp[prev+1][i]=max(op1,op2);
        }
        return dp[prev+1][i] = help(prev,i-1,nums,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        // dp[0]=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }

                // else{
                //     dp[i]=max(dp[i],dp[j]);
                // }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }

        return ans;    
    }
};