class Solution {
public:
    bool help(int idx,string &s,unordered_set<string> &st,vector<int> &dp){
        if(idx>=s.length())return true;
        if(dp[idx]!=-1)return dp[idx];
        string temp="";
        for(int i=idx;i<s.length();i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(help(i+1,s,st,dp))return true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string &word:wordDict){
            st.insert(word);
        } 
        vector<int> dp(s.length(),-1);
        return help(0,s,st,dp);   
    }
};