class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        if(n<3)return s;
        string res;
        res+=s[0];
        for(int i=1;i<n-1;i++){
            if(s[i]==s[i-1] && s[i]==s[i+1])continue;
            res+=s[i];
        }
        res+=s[n-1];
        return res;
    }
};