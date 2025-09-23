class Solution {
public:
    int getSum(int a, int b) {
        int carry=a&b;
        a=a^b;
        while(carry){
            b=a&(carry<<1);
            a=a^(carry<<1);
            carry=b;
        } 
        return a;   
    }
};