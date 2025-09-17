class Solution {
public:
    bool isPalindrome(string& s){
        if(s.empty())return false;
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isPalindrome(temp))ans++;
            }
        }
        return ans;
    }
};