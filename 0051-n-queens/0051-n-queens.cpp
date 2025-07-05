class Solution {
public:
    void help(vector<vector<string>>& res,vector<string> temp,vector<int>& col,vector<int>& rd,vector<int>& ld,int n,int i){
        if(i==n){
            res.push_back(temp);
            return;
        }

        
        for(int k=0;k<n;k++){
            if(col[k]==0 && rd[i+k]==0 && ld[i-k + n-1]==0){
                col[k]=1;
                rd[i+k]=1;
                ld[i-k + n-1]=1;

                string row(n,'.');
                row[k]='Q';
                temp.push_back(row);
                help(res,temp,col,rd,ld,n,i+1);
                temp.pop_back();

                col[k]=0;
                rd[i+k]=0;
                ld[i-k + n-1]=0;
            }  
        }


    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        vector<int> col(n,0);
        vector<int> rd(2*n-1,0);
        vector<int> ld(2*n-1,0);
        help(res,temp,col,rd,ld,n,0);

        return res;  
    }
};