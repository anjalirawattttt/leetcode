class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLength=0;
        int hashMap[256];
        fill(hashMap,hashMap+256,-1);

        while(r<s.length()){
            if(hashMap[s[r]]!=-1){
                if(hashMap[s[r]]>=l)l=hashMap[s[r]]+1;   
            }
            hashMap[s[r]]=r;
            maxLength=max(maxLength,r-l+1);
            r++;
        }
        return maxLength;
    }
};