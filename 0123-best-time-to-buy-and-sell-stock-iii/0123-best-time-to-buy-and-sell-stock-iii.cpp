class Solution {
public:
    // int help(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
    //     if(i==prices.size())return 0;
    //     if(cap==0)return 0;
    //     if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
    //     int profit=0;
    //     if(buy){
    //         profit = max ( -prices[i]+help(i+1,0,cap,prices,dp) , help(i+1,1,cap,prices,dp) );
    //     }
    //     else{
    //         profit = max ( +prices[i]+help(i+1,1,cap-1,prices,dp) , help(i+1,0,cap,prices,dp) );
    //     }
    //     return dp[i][buy][cap]=profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> next(2,vector<int>(3,0));

        //dp[n]...=0
        //dp[][][0]=0
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int>(3,0));
            for(int buy=0;buy<=1;buy++){
                for(int cap=2;cap>0;cap--){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[i]+next[0][cap],next[1][cap]);
                    } 
                    else{
                        profit=max(+prices[i]+next[1][cap-1],next[0][cap]);
                    } 
                    curr[buy][cap]=profit;
                }
            }
            next=curr;
        }



        return next[1][2];
        
    }
};