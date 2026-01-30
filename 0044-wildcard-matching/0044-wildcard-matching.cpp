class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        dp[0][0]=1;

        int j=0;
        while(j<m && p[j]=='*'){
            dp[0][j+1]=1;
            j++;
        }

        vector<int> temp(m+1,0);
        temp[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(temp[j-1])dp[i][j]=1;
                }
                else if(p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                if(dp[i][j]){
                    temp[j]=1;
                }
            }
        }

        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n][m];
    }
};