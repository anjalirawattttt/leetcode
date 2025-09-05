class Solution {
public:
    // int help(vector<int>& nums,int i){
    //     int op=1;
    //     for(int j=i-1;j>=0;j--){
    //         if(nums[j]<nums[i]){
    //             //take
    //             op = max( op , 1+help(nums,j) );
    //         }
    //     }
    //     return op;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            int op=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    //take
                    op = max( op , 1+dp[j] );
                }
            }
            dp[i]=op;
            ans=max(ans,op);
        }
        return ans;   
    }
};