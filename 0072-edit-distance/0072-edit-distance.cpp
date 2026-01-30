class Solution {
public:
    int help(int i1,string s1,int i2,string s2,vector<vector<int>> &dp){
        if(i1<0 && i2<0)return 0;
        if(i2<0){
            return i1+1;
        }
        if(i1<0){
            return i2+1;
        }

        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(s1[i1]==s2[i2]){
            return dp[i1][i2]=help(i1-1,s1,i2-1,s2,dp);
        }    
        //insert
        int op1=1+help(i1,s1,i2-1,s2,dp);
        //delete
        int op2=1+help(i1-1,s1,i2,s2,dp);
        //replace
        int op3=1+help(i1-1,s1,i2-1,s2,dp);
        return dp[i1][i2]=min(op1,min(op2,op3));

    }
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return help(n1-1,word1,n2-1,word2,dp);    
    }
};