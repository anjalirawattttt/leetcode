class Solution {
public:
    int minInsertions(string s) {
        //longest palindromic subsequence
        int n=s.length();
        string s2="";
        for(int i=n-1;i>=0;i--){
            s2+=s[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }

        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                if(s[i1-1]==s2[i2-1]){
                    dp[i1][i2]=1+dp[i1-1][i2-1];
                }
                //not match
                else{
                    dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
                }
            }
        }



        return n-dp[n][n]; 
    }
};