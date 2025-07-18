class Solution {
public:

    // int help(int n,vector<int>& nums,vector<int>& dp){
    //     if(n==0)return nums[n];
    //     if(n<0)return 0;
    //     if(dp[n]!=-1)return dp[n];
    //     //pick
    //     int op1=nums[n]+help(n-2,nums,dp);
    //     //not pick
    //     int op2=help(n-1,nums,dp);
    //     return dp[n]=max(op1,op2);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        int curri=INT_MIN;
        for(int i=1;i<n;i++){
            int op1=nums[i]+prev2;
            int op2=prev;
            curri=max(op1,op2);
            prev2=prev;
            prev=curri;
        }
        return prev;    
    }

};