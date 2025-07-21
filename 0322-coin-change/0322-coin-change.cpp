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
        int INF=INT_MAX/2;
        vector<int> prev(amount+1,INF);
        for(int a=0;a<=amount;a++){
            if(a % coins[0]==0) prev[a] = a / coins[0];
        }

        for(int i=1;i<n;i++){
            vector<int> curr(amount+1,INF);
            for(int a=0;a<=amount;a++){
                int op1=INF;
                if(a>=coins[i])op1=1+curr[a-coins[i]];
                //not pick
                int op2=prev[a];
                curr[a]=min(op1,op2);
            }
            prev=curr;
        }



        if(prev[amount]>=INF)return -1;
        return prev[amount];   
    }
};