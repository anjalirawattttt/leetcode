class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x>=0 && x<=9)return true;
        int rev=0;
        while(x>rev){
            int digit = x % 10;
            rev = rev * 10 + digit;
            if(rev==0)return false;
            x = x / 10;
        }  
        if(x==0)return false;
        return (x==rev) | (x==(rev/10));  
    }
};