class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());

        for(int i=0;i<=n;i++){
            if(!memcmp(s.c_str(),rev.c_str()+i,n-i)){
                int rem=i;
                return rev+s.substr(n-i,i);
            }
        } 
        return rev+s;
    }
};