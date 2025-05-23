class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());      
        int i=0;

        for(int &c:s){
            if(g[i]<=c)i++;
            if(i==g.size())break;
        }
        
        

        return i;
    }
};