class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal;
        int ans=0;
        //count no of set bits 
        while(n!=0){
            ans= ans + (n&1);
            n=n>>1;
        }  
        return ans;
    }
};