class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
        int n=s.length();
        for(int i=0;i<n;i++){
            string temp="";
            temp+=s.substr(i,n-i);
            temp+=s.substr(0,i);
            if(temp==goal)return true;
        }
        return false;
    }
};