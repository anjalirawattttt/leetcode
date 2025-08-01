class Solution {
public:
    int help(int i1,int i2,string s1,string s2,vector<vector<int>>& dp){
        if(i2<0){
            //delete
            return i1+1;
        }
        if(i1<0){
            //insert
            return i2+1;
        }
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2]){
            return dp[i1][i2]=help(i1-1,i2-1,s1,s2,dp);  
        }
        //insert
        int op1=1+help(i1,i2-1,s1,s2,dp);
        //delete
        int op2=1+help(i1-1,i2,s1,s2,dp);
        //replace
        int op3=1+help(i1-1,i2-1,s1,s2,dp);
        return dp[i1][i2]=min(op1,min(op2,op3));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(n-1,m-1,word1,word2,dp);    
    }
};