class Solution {
public:
    bool help(int i,string& s,unordered_set<string>& st,vector<int>& dp){
        if(i==s.length())return true;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(help(j+1,s,st,dp))return true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<int> dp(n,-1);
        if( help(0,s,st,dp) )return true;
        return false;
    }
};