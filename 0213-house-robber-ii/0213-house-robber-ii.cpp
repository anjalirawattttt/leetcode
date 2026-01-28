class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=nums[0];

        for(int i=1;i<n-1;i++){
            for(int j=0;j<2;j++){
                //take
                int op1=nums[i];
                if(i>1)op1+=dp[i-2][j];
                //not take
                int op2=dp[i-1][j];
                dp[i][j]=max(op1,op2);
            }
        }

        //n-1
        if(n>1){
            //take
            dp[n-1][0]=nums[n-1];
            //take
            if(n>2)dp[n-1][0]+=dp[n-3][0];
            //not take 
            dp[n-1][1]=dp[n-2][1];
        }

        return max(dp[n-1][0],dp[n-1][1]);
        
    }
};