class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());      
        int i=0,j=0;
        while(j<s.size() && i<g.size()){
            if(g[i]<=s[j]){
                ans++;
                j++;
                i++;
            }
            else{
                while(j<s.size() && g[i]>s[j]){
                    j++;
                }
            }
        }
        
        

        return ans;
    }
};