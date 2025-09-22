class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if( isalnum(s[i]) && isalnum(s[j]) ){
                if(s[i]>='A' && s[i]<='Z')s[i]+=32;
                if(s[j]>='A' && s[j]<='Z')s[j]+=32;
                if(s[i]!=s[j])return false;
                i++;
                j--;
            }
            else{
                if(!isalnum(s[i]))i++;
                if(!isalnum(s[j]))j--;
            }
        } 
        return true;
    }
};