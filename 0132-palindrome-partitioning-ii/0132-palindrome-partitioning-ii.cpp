class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    int help(int i,string &s,vector<int>& dp){
        if(i>=s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        int minCuts=INT_MAX;
        for(int j=i;j<s.length();j++){
            if(isPalindrome(i,j,s)){
                int cuts=1+help(j+1,s,dp);
                minCuts=min(minCuts,cuts);
            }
        }
        return dp[i]=minCuts;
    }

    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return help(0,s,dp)-1;    
    }
};