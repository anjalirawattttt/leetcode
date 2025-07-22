class Solution {
public:
    bool checkDivisibility(int n) {
        int ds=0;
        int dp=1;
        int num=n;
        while(num>0){
            int digit=num%10;
            ds+=digit;
            dp*=digit;
            num/=10;
        }  
        ds+=dp;
        if(n%ds==0)return true;
        return false;  
    }
};