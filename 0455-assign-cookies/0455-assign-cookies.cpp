class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());      
        int j=0;
        for(int i=0;i<g.size();i++){
            if(j>=s.size())break;
            if(g[i]<=s[j]){
                ans++;
                j++;
            }
            else{
                while(j<s.size() && g[i]>s[j]){
                    j++;
                }
                i--;
            }
        }

        

        return ans;
    }
};