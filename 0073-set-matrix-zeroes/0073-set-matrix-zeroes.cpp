class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto it=rows.begin();it!=rows.end();it++){
            int i=*it;
            for(int j=0;j<matrix[i].size();j++){
                matrix[i][j]=0;
            }
        }
        for(auto it=cols.begin();it!=cols.end();it++){
            int j=*it;
            for(int i=0;i<matrix.size();i++){
                matrix[i][j]=0;
            }
        }
    }
};