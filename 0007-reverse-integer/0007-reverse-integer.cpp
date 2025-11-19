class Solution {
public:
    int reverse(int x) {
        long long num=(long long)x;
        // cout<<num<<endl;
        bool pos=true;
        if(num<0){
            pos=false; 
            num=num*-1; 
        } 
        long long reverse=0;
        while(num>0){
            reverse = reverse*10 + (num%10);
            num=num/10;
        }
        if(!pos)reverse=reverse*-1;
        // cout<<reverse<<endl;
        if(reverse<INT_MIN || reverse>INT_MAX)return 0;
        return (int)reverse;
    }
};