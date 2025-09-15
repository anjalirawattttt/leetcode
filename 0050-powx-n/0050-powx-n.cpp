class Solution {
public:
    double help(double x,int N){
        if(N==0)return 1;
        double half=help(x,N/2);
        if(N%2==0){
            return half*half;
        }
        else{
            return x*half*half;
        }
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            N=-N;
            x=1/x;
        }
        return help(x,N);   
    }
};