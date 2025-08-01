class Solution {
public:
    // bool help(int i,int j,string s,string p,vector<vector<int>>& dp){
    //     if(i<0 && j<0)return true;
    //     if(j<0 && i>=0)return false;
    //     if(i<0 && j>=0){
    //         for(int k=0;k<=j;k++){
    //             if(p[k]!='*')return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
        
    //     if(p[j]=='?' || s[i]==p[j]){
    //         return dp[i][j]=help(i-1,j-1,s,p,dp);
    //     } 
    //     else if(p[j]=='*'){
    //         return dp[i][j]=help(i,j-1,s,p,dp) || help(i-1,j,s,p,dp);
    //     }
    //     return dp[i][j]=false;
    // }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();

        vector<bool> prev(m+1,false);

        prev[0]=true;
        for(int j=1;j<=m;j++){
            prev[j]= true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*')prev[j]= false;
            }
        }

        for(int i=1;i<=n;i++){
            vector<bool> curr(m+1,false);
            for(int j=1;j<=m;j++){
                if(p[j-1]=='?' || s[i-1]==p[j-1]){
                    curr[j]=prev[j-1];
                } 
                else if(p[j-1]=='*'){
                    curr[j]=curr[j-1] || prev[j];
                }
                else{
                    curr[j]=false;   
                }
            }
            prev=curr;
        }
        
        return prev[m];   
    }
};