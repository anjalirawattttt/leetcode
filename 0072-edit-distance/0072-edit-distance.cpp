class Solution {
public:
    int help(string &word1,int i1,string &word2,int i2,vector<vector<int>> &dp){
        if(i1==0 && i2==0)return word1[i1]==word2[i2]?0:1 ;
        if(i2<0)return i1+1;
        if(i1<0)return i2+1;
        if(dp[i1][i2]!=-1)return dp[i1][i2];

        if(word1[i1]==word2[i2]){
            return dp[i1][i2]=help(word1,i1-1,word2,i2-1,dp);
        }
        //insert
        int op1=1+help(word1,i1,word2,i2-1,dp);
        //delete 
        int op2=1+help(word1,i1-1,word2,i2,dp);
        //replace
        int op3=1+help(word1,i1-1,word2,i2-1,dp);
        return dp[i1][i2]=min(op1,min(op2,op3));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length(),n2=word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return help(word1,n1-1,word2,n2-1,dp);   
    }
};