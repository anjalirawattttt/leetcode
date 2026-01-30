class Solution {
public:
    int help(int i1,string &s1,int i2,string &s2){
        if(i1<0 && i2<0)return 0;
        if(i1<0){
            return i2+1;
        }
        if(i2<0){
            return i1+1;
        }
        int op1=INT_MAX;
        if(s1[i1]==s2[i2]){
            op1=1+help(i1-1,s1,i2-1,s2);
        }
        int op2=1+help(i1-1,s1,i2,s2);
        int op3=1+help(i1,s1,i2-1,s2);
        return min(op1,min(op2,op3));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.length();
        int n2=str2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(str1[i1-1]==str2[i2-1]){
                    dp[i1][i2]=1+dp[i1-1][i2-1];
                }
                else{
                    int op1=dp[i1-1][i2];
                    int op2=dp[i1][i2-1];
                    dp[i1][i2]=max(op1,op2);
                }
            }
        }

        //build shortest common subsequence
        int i=n1,j=n2;
        string result="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                result+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                result+=str1[i-1];
                i--;
            }
            else{
                result+=str2[j-1];
                j--;
            }
        }

        while(i>0){
            result+=str1[i-1];
            i--;
        }
        while(j>0){
            result+=str2[j-1];
            j--;
        }


        reverse(result.begin(),result.end());
        
        
        return result; 

    }
};