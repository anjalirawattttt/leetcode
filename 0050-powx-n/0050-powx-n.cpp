class Solution {
public:
    double help(double x,long n){
        if(n==0)return 1;
        double ans=1.0;
        while(n>0){
            if(n%2==1){
                ans=ans*x;
            }
            x=x*x;
            n=n>>1;
        }  
        return ans; 
    }
    double myPow(double x, int n) {
        if(n==0)return 1;
        long N=n;
        if(n<0)return help(1.0/x,-N);
        return help(x,N);
    }
};