class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        vector<int> hash(3,-1);
        int n=s.length();
        int l=0,r=0;
        while(r<n){
            hash[s[r]-'a']=r;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                int minIdx=min(hash[0],min(hash[1],hash[2]));
                ans+=minIdx+1;
            }
            r++;
        }
        return ans;    
    }
};