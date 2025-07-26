class Solution {
public:
    // int help(int i1,int i2,string s1,string s2,vector<vector<int>>& dp){
    //     if(i1<0 || i2<0)return 0;
    //     if(dp[i1][i2]!=-1)return dp[i1][i2];
    //     //match
    //     if(s1[i1]==s2[i2]){
    //         return dp[i1][i2]=1+help(i1-1,i2-1,s1,s2,dp);
    //     }
    //     //not match
    //     return dp[i1][i2]=max(help(i1-1,i2,s1,s2,dp),help(i1,i2-1,s1,s2,dp));
    // }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s2="";
        for(int i=n-1;i>=0;i--){
            s2+=s[i];
        }
        vector<int> prev(n+1,0);

        for(int i1=1;i1<=n;i1++){
            vector<int> curr(n+1,0);
            curr[0]=0;
            for(int i2=1;i2<=n;i2++){
                if(s[i1-1]==s2[i2-1]){
                    curr[i2]=1+prev[i2-1];
                }
                //not match
                else{
                    curr[i2]=max(prev[i2],curr[i2-1]);
                }
            }
            prev=curr;
        }



        return prev[n];           
    }
};