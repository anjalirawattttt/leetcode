class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=1;

        for(int i=n-2;i>=0;i--){
            bool ans=false;
            for(int j=i+1;j<=min(i+nums[i],n-1);j++){
                ans = ans || dp[j];
                if(ans)break;
            } 
            dp[i]=ans;   
        }

        return dp[0];
    }
};