class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,n=s.length(),ans=0;
        int map[3];
        fill(map,map+3,-1);

        while(r<n){
            map[s[r]-'a']=r;            
            if(map[0]!=-1 && map[1]!=-1 && map[2]!=-1){
                l=min(map[0],min(map[1],map[2]));
                ans+=l+1;
            }            
            r++;
        }  

        return ans;     
    }
};