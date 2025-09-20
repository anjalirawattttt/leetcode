class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int n=s.length();
        int l=0,r=0;
        unordered_map<char,int> m;
        int maxFreq=0;
        while(r<n){
            m[s[r]]++;
            maxFreq=max(maxFreq,m[s[r]]);
            if(r-l+1-maxFreq<=k)ans=max(ans,r-l+1);
            else{
                m[s[l]]--;
                l++;
                maxFreq=0;
                for(auto &p:m){
                    maxFreq=max(maxFreq,p.second);
                }
            }
            r++;
        }
        return ans;    
    }
};