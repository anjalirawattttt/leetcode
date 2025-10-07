class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1=s.length(),n2=t.length();
        if(n1>n2)return false;
        int i1=0,i2=0;
        while(i2<n2){
            if(s[i1]==t[i2]){
                i1++;
            }
            i2++;
        }
        return i1==n1;

    }
};