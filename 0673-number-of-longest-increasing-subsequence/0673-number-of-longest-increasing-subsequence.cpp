class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        vector<int> nolis(n,1);
        vector<int> parent(n,-1);
        vector<int> dp(n,1);
        // nolis[0]=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]<1+dp[j]){
                        parent[i]=j;
                        dp[i]=1+dp[j];
                        nolis[i]=nolis[j];
                    }
                    else if(dp[i]==1+dp[j]){
                        nolis[i]+=nolis[j];
                    }
                }
            }
        }
        // int ans=INT_MIN;
        int maxLen=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxLen){
                maxLen=dp[i];
                ans=nolis[i];
            }
            else if(dp[i]==maxLen){
                ans+=nolis[i];
            }
        }

        return ans;    
    }
};