class Solution {
public:
    int help(int i,vector<int>& arr, int k,vector<int>& dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=0;
        int num=arr[i];
        int n=arr.size(),len=0;
        for(int j=i;j< min(n,i+k);j++){
            len++;
            num=max(num,arr[j]);
            int sum=(len)*num + help(j+1,arr,k,dp);
            maxi=max(maxi,sum);
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxi=0,num=arr[i],len=0;
            for(int j=i;j< min(n,i+k);j++){
                len++;
                num=max(num,arr[j]);
                int sum=(len)*num + dp[j+1];
                maxi=max(maxi,sum);
            }
            dp[i]=maxi;  
        }
        return dp[0];   
    }
};