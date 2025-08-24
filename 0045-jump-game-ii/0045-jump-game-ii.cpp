class Solution {
public:

    
   

    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int l=0,r=0,jumps=0;

        while(r<n-1){
            int a=l,b=r;
            for(int i=a;i<=b;i++){
                r=max(r,i+nums[i]);
            }
            if(r>b){
                l=b+1;
            }
            jumps++;
        }
        return jumps;  

    }
};