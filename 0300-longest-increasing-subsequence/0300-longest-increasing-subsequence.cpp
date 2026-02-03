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
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //tabulation


        // BASECASE dp[prev][0]=0;

        for(int i=1;i<=n;i++){
            //idx=i-1
            for(int prev=0;prev<=n;prev++){
                //prev==0 means prev==-1
                //real idx prev-1
                if(prev==0 || nums[prev-1]>nums[i-1]){
                    //take
                    int op1=1+dp[i][i-1];
                    //not take
                    int op2=dp[prev][i-1];
                    dp[prev][i]=max(op1,op2);
                }
                else{
                    dp[prev][i]=dp[prev][i-1];
                }
            }
        }

        return dp[0][n];    
    }
};