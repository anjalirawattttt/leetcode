class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int l=0,r=0;
        int n=s.length();
        int maxFreq=0,maxLength=0;
        while(r<n){
            m[s[r]]+=1;
            maxFreq=max(maxFreq,m[s[r]]);
            int windowSize=r-l+1;

            if(windowSize-maxFreq>k){
                m[s[l]]-=1;
                l++;
            }

            if(windowSize-maxFreq<=k){
                maxLength=max(maxLength,windowSize);
            }            
            r++;
        }
        return maxLength;
    }
};