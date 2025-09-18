class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)return 0;
        vector<int> hash(128,-1);
        int l=0,r=0;
        int maxLen=1;
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l=hash[s[r]]+1;    
            }
            hash[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};