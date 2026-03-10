class Solution {
public:
    int help(int i,string s,vector<int> &dp){
        if(i==s.length())return 1;
        if(s[i]=='0')return 0;

        int idx=i;

        if(dp[i]!=-1)return dp[i];

        int ans=0;
        string temp="";
        while(i<s.length()){
            temp+=s[i];
            if(stoi(temp)<27)ans+=help(i+1,s,dp);
            else break;
            i++;
        }
        return dp[idx]=ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return help(0,s,dp);   
    }
};