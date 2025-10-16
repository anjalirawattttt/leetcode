class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int x=-1,y=-1;
        for(int i=0;i<mat.size();i++){
            int n1=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)n1++;
            }
            if(n1>y){
                x=i;
                y=n1;
            }
        }
        return {x,y};   
    }
};