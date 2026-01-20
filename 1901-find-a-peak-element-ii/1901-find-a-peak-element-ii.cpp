class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int r=0,c=0;
        while(r>=0 && c>=0 && r<m && c<n){
                int top = r>0 ? mat[r-1][c] : -1;
                int bottom = r<m-1 ? mat[r+1][c] : -1;
                int left = c>0 ? mat[r][c-1] : -1;
                int right= c<n-1 ? mat[r][c+1] : -1;
                if(mat[r][c]>top && mat[r][c]>bottom && mat[r][c]>left && mat[r][c]>right){
                    return {r,c};
                }
                else if(left>mat[r][c]){
                    c--;
                }
                else if(right>mat[r][c]){
                    c++;
                }
                else if(top>mat[r][c]){
                    r--;
                }
                else{
                    r++;
                }
        } 
        return {-1,-1};   
    }
};