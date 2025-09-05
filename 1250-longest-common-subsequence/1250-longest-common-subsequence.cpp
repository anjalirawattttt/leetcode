class Solution {
public:
    int help(string text1, string text2,int i1,int i2,vector<vector<int>> &dp){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(text1[i1]==text2[i2]){
            return dp[i1][i2]=1+help(text1,text2,i1-1,i2-1,dp);
        }
        int op1=help(text1,text2,i1-1,i2,dp);
        int op2=help(text1,text2,i1,i2-1,dp);
        return dp[i1][i2]=max(op1,op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(text1[i1-1]==text2[i2-1]){
                    dp[i1][i2]=1+dp[i1-1][i2-1];
                }
                else{
                    int op1=dp[i1][i2-1];
                    int op2=dp[i1-1][i2];
                    dp[i1][i2]=max(op1,op2);
                }
            }
        }
        return dp[n1][n2];
    }
};