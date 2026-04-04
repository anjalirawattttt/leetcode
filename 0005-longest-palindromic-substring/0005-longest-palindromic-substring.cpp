class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start=-1;
        int maxLen=0;
        for(int i=0;i<n;i++){
            //odd
            int l=i,r=i;
            while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                l--;
                r++;
            }

            if(r-l+1>maxLen){
                maxLen = r-l+1;
                start=l;
            }

            //even
            if(i>0 && s[i-1]==s[i]){
                l=i-1 , r=i;
                while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                    l--;
                    r++;
                }
                if(r-l+1>maxLen){
                    maxLen = r-l+1;
                    start=l;
                }
            }
        }   
        return maxLen==0 ? "" : s.substr(start,maxLen); 
    }
};