class Solution {
public:
    int help(int n){
        int bits=0;
        while(n>0){
            int x=n&1;
            if(x)bits++;
            n=n>>1;
        }
        return bits;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=help(i);
        }
        return ans;   
    }
};