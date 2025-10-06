class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int> m;
        int l=0,r=0;
        while(r<n){
            if(m.find(s[r])!=m.end()){
                l=m[s[r]]+1;
            }
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;     
        }
        return ans;    
    }
};