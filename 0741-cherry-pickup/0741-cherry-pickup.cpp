class Solution {
public:
    int help(vector<vector<int>>& grid,int r1,int r2,int c1,int n,vector<vector<vector<int>>>& dp){
        int c2=r1+c1-r2;
        if(r1>=n || r2>=n || c1>=n ||c2>=n)return -1e8;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)return -1e8;
        if(r1==n-1 && c1==n-1 && r2==n-1 && c2==n-1)return grid[n-1][n-1];

        if(dp[r1][r2][c1]!=-1)return dp[r1][r2][c1];
        int cherries=0;
        if(r1==r2 && c1==c2)cherries=grid[r1][c1];
        else cherries=grid[r1][c1]+grid[r2][c2];
        
        int temp=max({
            help(grid,r1+1,r2+1,c1,n,dp),
            help(grid,r1,r2,c1+1,n,dp),
            help(grid,r1+1,r2,c1,n,dp),
            help(grid,r1,r2+1,c1+1,n,dp)
        });

        return dp[r1][r2][c1]=cherries+temp;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> front(n,vector<int>(n,0));
        vector<vector<int>> curr(n,vector<int>(n,0));


        for(int r1=n-1;r1>=0;r1--){
            for(int r2=n-1;r2>=0;r2--){
                for(int c1=n-1;c1>=0;c1--){

                    int c2=r1-r2+c1;
                    if(c2<0 || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
                        curr[r2][c1]=-1e8;
                        continue;
                    }

                    if(r1==n-1 && c1==n-1 && r2==n-1 && c2==n-1){
                        curr[r2][c1]=grid[r1][c1];
                    }
                    else{
                        int cherries=0;
                        if(r1==r2 && c1==c2)cherries=grid[r1][c1];
                        else cherries=grid[r1][c1]+grid[r2][c2];

                        int op1=-1e8,op2=-1e8,op3=-1e8,op4=-1e8;
                        if(r1<n-1 && r2<n-1)op1=front[r2+1][c1];
                        if(c1<n-1 && c2<n-1)op2=curr[r2][c1+1];
                        if(r2<n-1 && c1<n-1)op3=curr[r2+1][c1+1];
                        if(r1<n-1 && c2<n-1)op4=front[r2][c1];

                        int temp=max({op1,op2,op3,op4});
                        curr[r2][c1]=cherries+temp;
                    }

                }
            }
            front=curr;
        }


        return max(0,front[0][0]);   
    }
};