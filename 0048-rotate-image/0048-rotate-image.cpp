class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //clockwise->
        //reverse cols
        int n=matrix.size();
        for(int j=0;j<n;j++){
            for(int i=0;i<=(n-1)/2;i++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }    
        }
        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};