class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        vector<int> prev(amount+1,1e7);
        //base case amount ==0 =>0
        prev[0]=0;
        //i-1
        for(int i=1;i<=n;i++){
            vector<int> curr(amount+1,1e7);
            curr[0]=0;
            for(int a=1;a<=amount;a++){
                //take
                int op1=1e7;
                if(a>=coins[i-1])op1=1+curr[a-coins[i-1]];
                //not take
                int op2=prev[a];
                curr[a]=min(op1,op2);    
            }
            prev=curr;
        }

        int ans=prev[amount];
        return ans>=1e7?-1:ans;    
    }
};