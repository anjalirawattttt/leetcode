class Solution {
public:
    //tabulation - bottom up tc O(n) sc O(1)
    int fib(int n) {
        if(n<=1)return n;
        int prev2=0;
        int prev=1;
        int ans;
        for(int i=2;i<=n;i++){
            ans=prev+prev2;
            prev2=prev;
            prev=ans;
        }
        return ans;
    }
};