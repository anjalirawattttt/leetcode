class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int ele=arr[i];
            for(int j=i;j<min(n,i+k);j++){
                int len=j-i+1;
                ele=max(ele,arr[j]);
                dp[i]=max(dp[i],len*ele+dp[i+len]);
            }
        }   
        return dp[0]; 
    }
};