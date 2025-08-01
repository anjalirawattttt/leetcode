class Solution {
public:
    // int help(int i,int j,string s,string t,vector<vector<int>> &dp){
    //     if(j<0)return 1;
    //     if(i<0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==t[j]){
    //         return dp[i][j]=help(i-1,j-1,s,t,dp)+help(i-1,j,s,t,dp);
    //     }
    //     //else
    //     return dp[i][j]=help(i-1,j,s,t,dp);
    // }

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m==0)return 1;
        if(n==0 || m>n)return 0;
        const int MOD = 1e9 + 7;
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            curr[0]=1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=(prev[j-1]+prev[j])%MOD;
                }
                else{
                    curr[j]=prev[j];
                }   
            }
            prev=curr;
        }
        return prev[m];   
    }
};