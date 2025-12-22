class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
        long long num=x;
        long long reverse=0;
        while(num>0){
            reverse=(reverse*10)+(num%10);
            num/=10;
        } 
        num=x;   
        return num==reverse; 
    }
};