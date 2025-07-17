class Solution {
public:
    int help(int n,vector<int> &cost,vector<int>& dp){ 
        if(n<0)return 0;
        if(n==0||n==1)return cost[n];
        if(dp[n]!=-1)return dp[n];

        return dp[n]=cost[n]+min(help(n-1,cost,dp),help(n-2,cost,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);

        return min(help(n-1,cost,dp),help(n-2,cost,dp)); 
    }
};