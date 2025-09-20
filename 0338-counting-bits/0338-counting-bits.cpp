class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int num=i;
            int temp=0;
            while(num>0){
                if(num&1)temp++;
                num=num>>1;
            }
            ans[i]=temp;
        }
        return ans;
    }
};