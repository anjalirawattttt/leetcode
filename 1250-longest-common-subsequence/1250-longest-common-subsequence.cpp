class Solution {
public:
    int help(int i1,string &s1,int i2,string &s2,vector<vector<int>> &dp){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        //take
        if(s1[i1]==s2[i2])return dp[i1][i2]=1+help(i1-1,s1,i2-1,s2,dp);
        //not take
        int op1=help(i1-1,s1,i2,s2,dp);
        int op2=help(i1,s1,i2-1,s2,dp);
        return dp[i1][i2]=max(op1,op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        //base case -> 0
        for(int i1=1;i1<n1+1;i1++){
            for(int i2=1;i2<n2+1;i2++){
                //take
                if(text1[i1-1]==text2[i2-1])dp[i1][i2]=1+dp[i1-1][i2-1];
                //not take  
                else{
                    int op1=dp[i1-1][i2];
                    int op2=dp[i1][i2-1];
                    dp[i1][i2]=max(op1,op2);
                } 
            }
        }
        return dp[n1][n2];    
    }
};