class Solution {
public:
    void help(int &ans,vector<int>& col,vector<int>& rd,vector<int>& ld,int n,int i){
        if(i==n){
            ans++;
            return;
        }
        for(int k=0;k<n;k++){
            if(col[k]==0 && rd[i+k]==0 && ld[i-k + n-1]==0){
                col[k]=1;
                rd[i+k]=1;
                ld[i-k+n-1]=1;
                
                help(ans,col,rd,ld,n,i+1);

                col[k]=0;
                rd[i+k]=0;
                ld[i-k+n-1]=0;    
            }
        }
    }

    int totalNQueens(int n) {
        int ans=0;
        vector<int> col(n,0);
        vector<int> rd(2*n-1,0);
        vector<int> ld(2*n-1,0);
        help(ans,col,rd,ld,n,0);
        return ans;  
    }
};