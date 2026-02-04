class Solution {
public:
    // long long help(int i,int j,vector<int> &nums,vector<vector<long long>>  &dp){
    //     if(i>j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     long long maxCoins=INT_MIN;
    //     for(int k=i;k<=j;k++){
    //         long long coins = (nums[i-1]*nums[k]*nums[j+1]) + help(i,k-1,nums,dp) + help(k+1,j,nums,dp) ;
    //         maxCoins=max(maxCoins,coins); 
    //     }
    //     // cout << i << "," << j << "->" << maxCoins << endl;
    //     return dp[i][j]=maxCoins;
    // }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long> (n,0));
        //last guy 
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                long long maxCoins=INT_MIN;
                for(int k=i;k<=j;k++){
                    long long coins = (nums[i-1]*nums[k]*nums[j+1]) + dp[i][k-1] + dp[k+1][j] ;
                    maxCoins=max(maxCoins,coins); 
                }
                dp[i][j]=maxCoins;
            }
        }
        return dp[1][n-2];    
    }
};