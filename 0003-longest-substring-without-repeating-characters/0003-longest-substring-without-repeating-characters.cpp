class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        vector<int> hash(255,-1);
        int l=0,r=0;
        while(r<s.length()){
            if(hash[ (int)s[r] ]==-1){
                hash[ (int)s[r] ]=r;   
            }
            else{
                if(hash[ (int)s[r] ]>=l)l=hash[ (int)s[r] ]+1;
                hash[ (int)s[r] ]=r;
            }            
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;    
    }
};