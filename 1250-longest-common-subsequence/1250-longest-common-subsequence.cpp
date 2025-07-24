class Solution {
public:
    // int help(int i1,int i2,string text1, string text2,vector<vector<int>>& dp){
    //     if(i1<0 || i2<0 )return 0;
    //     if(dp[i1][i2]!=-1)return dp[i1][i2];
    //     //match
    //     if(text1[i1]==text2[i2])return dp[i1][i2]=1+help(i1-1,i2-1,text1,text2,dp);
    //     //not match
    //     return dp[i1][i2]=max(help(i1-1,i2,text1,text2,dp),help(i1,i2-1,text1,text2,dp));
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<int> prev(n2+1,0);

        for(int i1=1;i1<=n1;i1++){
            vector<int> curr(n2+1,0);
            for(int i2=1;i2<=n2;i2++){
                if(text1[i1-1]==text2[i2-1]) curr[i2]=1+prev[i2-1];
                //not match
                else{
                    curr[i2]=max(prev[i2],curr[i2-1]);
                }
            }
            prev=curr;
        }
        return prev[n2];      
    }
};