class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashMap[256];  
        fill(hashMap, hashMap + 256, -1);
        int l=0,r=0,maxLength=0;
        while(r<s.length()){
            if(hashMap[s[r]]!=-1){
                if(hashMap[s[r]]>=l)l=hashMap[s[r]]+1;
            }
            int length=r-l+1;
            maxLength=max(maxLength,length);
            hashMap[s[r]]=r;
            r++;
        }

        return maxLength;    
    }
};