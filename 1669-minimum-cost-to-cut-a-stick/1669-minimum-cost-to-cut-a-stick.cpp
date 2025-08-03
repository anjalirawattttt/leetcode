class Solution {
public:
    // int help(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
    //     if(i>j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j]; 
    //     int mini=INT_MAX;
    //     for(int k=i;k<=j;k++){
    //         int cost=(cuts[j+1]-cuts[i-1]) + help(i,k-1,cuts,dp) + help(k+1,j,cuts,dp);
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }

    int minCost(int n, vector<int>& cuts) {
               
        //add 0,n
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        int c=cuts.size();       
        vector<vector<int>> dp(c,vector<int>(c,0));

        for(int i=c-2;i>=1;i--){
            for(int j=1;j<=c-2;j++){
                if(i>j)continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost=(cuts[j+1]-cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }


        return dp[1][c-2];
    }
};