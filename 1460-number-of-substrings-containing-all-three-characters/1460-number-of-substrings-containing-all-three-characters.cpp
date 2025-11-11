class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,n=s.length();
        int characters=0;
        unordered_map<char,int> m;
        int ans=0;
        while(r<n){
            if(m.find(s[r])==m.end())characters++;
            m[s[r]]=r;
            if(characters==3){
                int minIdx=INT_MAX;
                for(auto &p:m){
                    minIdx=min(minIdx,p.second);
                }
                ans+=1+minIdx;
            }
            r++;
        }
        return ans;        
    }
};