class Solution {
public:
    double pow(double x,long long N){
        if(N==0)return 1;
        double temp=pow(x,N/2);
        if(N%2==0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
    }
    
    double myPow(double x, int n) {
        long long N=n; 
        if(N<0){
            x=1/x;
            N=-N;
        }
        double result=pow(x,N);
        return result;  
    }
};