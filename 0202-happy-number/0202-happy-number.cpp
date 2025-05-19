class Solution {
public:
    bool isHappy(int n) {
        int num=n;
        int sum=0;
        int i=100;
        while(i--){
            while(num>0){
                int digit=num%10;
                sum+=digit*digit;
                num/=10;
            }
            if(sum==1 || sum==7)return true;
            if(sum==2||sum==3||sum==4||sum==5||sum==6||sum==8||sum==9)return false;
            num=sum;
            sum=0;
        }        
        return false;
    }
};