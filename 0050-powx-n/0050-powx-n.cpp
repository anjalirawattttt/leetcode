class Solution {
public:
    double myPow(double x,long long N){

        if(N==0)return 1.00000;
        double temp=pow(x,N/2);
        if(N>0){
            if(N%2==0){
                return temp*temp;
            }
            else{
                return temp*temp*x;
            }
        }
        else{
            if(N%2==0){
                return temp*temp;
            }
            else{
                return temp*temp*(1/x);
            }
        }

    }
};