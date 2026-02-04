class Solution {
public:
    long long help(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long minCost=INT_MAX;
        for(int k=i;k<=j;k++){
            //cut at k
            long long cost=cuts[j+1]-cuts[i-1]+help(i,k-1,cuts,dp)+help(k+1,j,cuts,dp);
            minCost=min(minCost,cost);
        }
        // cout<<i<<","<<j <<"->" <<minCost<<endl;
        return dp[i][j]=minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int size=cuts.size();
        vector<vector<int>> dp(size+2,vector<int>(size+2,-1));
        return (int)help(1,cuts.size()-2,cuts,dp); 
    }
};