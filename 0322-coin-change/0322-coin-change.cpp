class Solution {
public:
    // int help(vector<int>& coins, int amount,int i,vector<vector<int>> &dp){
    //     if(amount==0)return 0;
    //     if(i<0)return INT_MAX;
    //     if(dp[i][amount]!=-1)return dp[i][amount];
    //     //pick
    //     int op1=1e7;
    //     if(amount>=coins[i])op1=1+help(coins,amount-coins[i],i,dp);
    //     //not pick
    //     int op2=help(coins,amount,i-1,dp);
    //     return dp[i][amount]=min(op1,op2);

    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e7));
        for(int i=0;i<n;i++)dp[i][0]=0;

        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0)dp[0][j]=j/coins[0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                //pick
                int op1=1e7;
                if(j>=coins[i])op1=1+dp[i][j-coins[i]];
                //not pick
                int op2=dp[i-1][j];
                dp[i][j]=min(op1,op2);
            }
        }
        int x=dp[n-1][amount];
        return x>=1e7?-1:x;    
    }
};