class Solution {
public:
    int next(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n=n/10;
        } 
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=next(n);
        while(slow!=fast && fast!=1 && fast!=7){
            slow=next(slow);
            fast=next(next(fast));
        }
        if(fast==1 || fast==7)return true;
        return false;
    }
};