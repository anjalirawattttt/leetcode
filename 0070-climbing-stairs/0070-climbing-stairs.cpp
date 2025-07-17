class Solution {
public:
    
        

    int climbStairs(int n) {
        if(n<0)return 0;
        if(n==0 || n==1)return 1;
        int curri;
        int prev=1;
        int prev2=1;

        for(int i=2;i<=n;i++){
            curri=prev+prev2;
            prev2=prev;
            prev=curri;
        }
        
        
        return curri;
    
    }
};