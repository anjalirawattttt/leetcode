class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;

        bool sign=true;
        if(dividend>=0 && divisor<0)sign=false;
        if(dividend<0 && divisor>0)sign=false;  
        long p=labs((long)dividend),q=labs((long)divisor);
        long ans=0;
        while(p>=q){
            int count=0;
            while( p>=(q<<(count+1)) )count++;
            p-=(q<<count);
            ans+=(1L<<count);
        }  
        if(ans>INT_MAX){
            return sign?INT_MAX:INT_MIN;
        }

        return sign ? ans : (-1*ans);
    }
};