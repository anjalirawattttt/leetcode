class Solution {

public:
    bool help(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(help(i,j-1,s) || help(i+1,j,s))return true;
                else return false;
            }
        }
        return true;
    }
};