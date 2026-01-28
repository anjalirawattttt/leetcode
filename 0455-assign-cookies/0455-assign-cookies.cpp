class Solution {
public:
    bool static cmp(const int &a,const int &b){
        return a>b;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),cmp);
        sort(s.begin(),s.end(),cmp);

        int size_g=g.size();
        int size_s=s.size();

        int i=0,j=0;

        while( i < size_s && j < size_g ){
            if(s[i]>=g[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }    

        return i;
    }
};