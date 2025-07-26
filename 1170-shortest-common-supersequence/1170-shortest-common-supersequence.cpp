
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n1;i++)dp[i][0]=0;
        for(int i=0;i<=n2;i++)dp[0][i]=0;

        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(str1[i1-1]==str2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                //not match
                else{
                    dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
                }
            }
        }     
    
        int i=n1,j=n2;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];  
                j--; 
            }
        }

        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};