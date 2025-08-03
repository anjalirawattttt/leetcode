class Solution {
public:
    int help(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j]; 
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=(cuts[j+1]-cuts[i-1]) + help(i,k-1,cuts,dp) + help(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }

    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        //add 0,n
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int c=cuts.size();

        
        vector<vector<int>> dp(c,vector<int>(c,-1));

        return help(1,c-2,cuts,dp);
    }
};