class Solution {
public:
    int help(int i,vector<int> &v,int rem,vector<vector<int>> &dp){
        if(rem==0)return 0;
        if(i<0)return 1e5;

        if(dp[i][rem]!=-1)return dp[i][rem];

        int op1=1e5;
        //take
        if(v[i]<=rem){
            op1=1+help(i,v,rem-v[i],dp);
        }
        //not take
        int op2=help(i-1,v,rem,dp);
        return dp[i][rem]=min(op1,op2);

    }
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i*i<=n;i++){
            v.push_back(i*i);
        }  
        vector<vector<int>> dp(v.size(),vector<int> (n+1,-1));
        int ans=help(v.size()-1,v,n,dp);
        return ans;      
    }
};