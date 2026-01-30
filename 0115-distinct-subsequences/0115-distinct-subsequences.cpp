class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<unsigned long long> dp(n2+1,0);
        dp[0]=1;

        for(int i1=1;i1<=n1;i1++){
            for(int i2=n2;i2>0;i2--){
                if(s[i1-1]==t[i2-1]){
                    dp[i2]+=dp[i2-1];
                }
            }
        } 
        return (int)dp[n2];   
    }
};