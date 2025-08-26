class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=0;
        unordered_map<char,int> m;
        int n=s.length();
        int l=0,r=0,maxFreq=0; 

        while(r<n){
            m[s[r]]++;  
            if(m[s[r]]>maxFreq)maxFreq=m[s[r]];
            if((r-l+1)-maxFreq>k){
                m[s[l]]--;
                l++;
                maxFreq=0;
                for(int i=l;i<=r;i++){
                    maxFreq=max(maxFreq,m[s[i]]);   
                }
            }
            if((r-l+1)-maxFreq<=k)maxLen=max(maxLen,r-l+1); 
            r++;
        }
        return maxLen;  
    }
};