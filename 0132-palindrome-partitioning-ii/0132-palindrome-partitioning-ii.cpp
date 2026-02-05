class Solution {
public:
    bool isPalindrome(string &temp){
        int l=0,r=temp.size()-1;
        while(l<r){
            if(temp[l]!=temp[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int help(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        string temp="";
        int minPalindromes=INT_MAX;
        for(int k=i;k<=j;k++){
            temp+=s[k];
            int palindromes=0;
            if(isPalindrome(temp)){
                palindromes=1+help(k+1,j,s,dp);
                minPalindromes=min(minPalindromes,palindromes);
            }
        }
        return dp[i][j]=minPalindromes;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(0,n-1,s,dp)-1;   
    }
};