class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gi=0,si=0;
        while(gi<g.size() && si<s.size()){
            while(si<s.size() && g[gi]>s[si]){
                si++;
            }
            if(si==s.size())break;
            gi++;
            si++;
        }
        return gi;    
    }
};