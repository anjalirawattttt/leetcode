class Solution {
public:
    
    bool isPalindrome(string s) {
        string final="";
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
                final += ch;
            }
            else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                final += ch;
            }
        } 
        int l=0,r=final.length()-1;
        while(l<r){
            if(final[l]!=final[r])return false;
            l++;
            r--;
        }
        return true;  
    }
};