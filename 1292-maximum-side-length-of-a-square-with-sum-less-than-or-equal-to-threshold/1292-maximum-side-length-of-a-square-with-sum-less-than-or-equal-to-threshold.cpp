class Solution {
public:
    int help(const vector<vector<int>> &p,int x1,int y1,int x2,int y2){
        return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> p(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int ans=0;

        int l=1,r=min(m,n);
        while(l<=r){
            int mid = l + (r-l)/2;
            bool find=false;
             for(int i=1;i<=m-mid+1;i++){
                for(int j=1;j<=n-mid+1;j++){
                    if(help(p,i,j,i+mid-1,j+mid-1)<=threshold){
                        find=true;
                    }
                }
            }
            if(find){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
        
    }
};