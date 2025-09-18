class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=0;
        string ans;
        for(int i=0;i<n;i++){
            //expand around center
            //odd expansion
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen<r-l+1){
                    maxLen=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            //even expansion
            l=i-1;
            r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen<r-l+1){
                    maxLen=r-l+1;
                    ans=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};