class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            //odd
            int l=i,r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
            //even
            if(i%2==0){
                l=i-1,r=i;
                while(l>=0 && r<s.length() && s[l]==s[r]){
                    ans++;
                    l--;
                    r++;
                }
                l=i,r=i+1;
                while(l>=0 && r<s.length() && s[l]==s[r]){
                    ans++;
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};