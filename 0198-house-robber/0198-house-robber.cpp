class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            //rob
            int op1=nums[i];
            if(i>1)op1+=dp[i-2];
            //not rob
            int op2=dp[i-1];
            dp[i]=max(op1,op2);
        }
        return dp[n-1];    
    }
};