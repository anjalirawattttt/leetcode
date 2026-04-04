class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            //odd
            int l=i,r=i;
            while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                l--;
                r++;
            }

            ans += (r-l+1)/2 + 1;

            //even
            if(i>0 && s[i-1]==s[i]){
                l=i-1 , r=i;
                while(l>0 && r<n-1 && s[l-1]==s[r+1]){
                    l--;
                    r++;
                }
                ans += (r-l+1)/2 ;
            }
        }   
        return ans;  
    }
};