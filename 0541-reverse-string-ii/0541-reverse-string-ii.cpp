class Solution {
public:
    void helper(string &res,int l,int r){
        if(r>=res.length())r=res.length()-1;
        if(l>=r)return;
        swap(res[l],res[r]);
        helper(res,l+1,r-1);
    }

    string reverseStr(string s, int k) {
        string res=s;
        int l=0;

        while(l<s.length()){
            helper(res,l,l+k-1);
            l+=2*k;
        } 

        return res;
    }
};