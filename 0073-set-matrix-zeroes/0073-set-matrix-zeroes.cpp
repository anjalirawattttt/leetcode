class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row.find(i)!=row.end() || col.find(j)!=col.end()){
                    matrix[i][j]=0;
                }
            }
        }
        // for(int r: row){
        //     int i=0;
        //     while(i<m){
        //         matrix[r][i]=0;
        //     }

        // }
        // for(int c:col){
        //     int i=0;
        //     while(i<n){
        //         matrix[i][c]=0;
        //     }
        // }
        row.clear();
        col.clear();
    }
};