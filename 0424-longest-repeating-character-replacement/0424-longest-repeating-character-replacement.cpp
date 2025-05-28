class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.length();
        int maxFreq=0,maxLength=0;
        unordered_map<char,int> m;

        while(r<n){
            m[s[r]]++;
            maxFreq=max(maxFreq,m[s[r]]);
            int windowSize=r-l+1;
            if(windowSize-maxFreq>k){
                m[s[l]]--;
                l++;
            }

            if(windowSize-maxFreq<=k){
                maxLength=max(maxLength,r-l+1);
            }

            r++;
        }
        return maxLength;
    }
};