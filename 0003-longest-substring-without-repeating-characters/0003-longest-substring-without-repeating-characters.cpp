class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,r=0,maxLen=0;
        vector<int> hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){
                l=max(l,hash[s[r]]+1);
            }
            hash[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};