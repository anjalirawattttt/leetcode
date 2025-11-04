class Solution {
public:
    // int help(int num,vector<int> &dp){
    //     if(num==0)return 0;
    //     if(dp[num]!=-1)return dp[num];
        

    //     int op=INT_MAX;
    //     for(int i=num;i>=1;i--){
    //         int sq=(int) sqrt(i);
    //         if(sq*sq==i){
    //             op=min(op,num/i+help(num%i,dp));
    //         }
    //     }
    //     return dp[num]=op;
    // }
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int num=1;num<=n;num++){
            for(int i=1;i*i<=num;i++){
                int square=i*i;
                dp[num]=min(dp[num],1+dp[num-square]);
            }  
        }



        return dp[n];    
    }
};