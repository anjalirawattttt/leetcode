class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x<0 )return 0;
        int l=1,r=x,mid;
        int ans=0;

        while(l<=r){
            mid=l + (r-l)/2;
            long long s=1LL*mid*mid;
            if(s==x)return mid;
            else if(s<x){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};