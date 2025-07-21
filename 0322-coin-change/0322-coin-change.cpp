class Solution {
public:
    // int help(vector<int>& coins, int amount,int i,vector<vector<int>>& dp){
    //     if(i==0){
    //         if(amount%coins[0]==0)return amount / coins[0];
    //         else return 1e9;
    //     } 
    //     if(dp[i][amount]!=-1)return dp[i][amount];
    //     //pick
    //     int op1=INT_MAX;
    //     if(amount>=coins[i])op1=1+help(coins,amount-coins[i],i,dp);
    //     //not pick
    //     int op2=help(coins,amount,i-1,dp);
    //     return dp[i][amount]=min(op1,op2);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0)dp[0][a]= a / coins[0];
        }

        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int op1=INT_MAX;
                if(a>=coins[i])op1=1+dp[i][a-coins[i]];
                //not pick
                int op2=dp[i-1][a];
                dp[i][a]=min(op1,op2);
            }
        }



        if(dp[n-1][amount]>=1e8)return -1;
        return dp[n-1][amount];   
    }
};