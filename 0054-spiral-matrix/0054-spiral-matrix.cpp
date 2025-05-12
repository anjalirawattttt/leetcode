class Solution {
public:
    void spiralRec(int &left,int &right,int &top,int &bottom,vector<vector<int>> &matrix,vector<int> &v){
        if(top>bottom || left>right)return ;
        //left to right
        for(int i=left;i<=right;i++){
            v.push_back(matrix[top][i]);
        }
        top++;
        //top to bottom
        for(int i=top;i<=bottom;i++){
            v.push_back(matrix[i][right]);
        }
        right--;
        //right to left
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        //bottom to top
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        spiralRec(left,right,top,bottom,matrix,v);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1;
        int top=0,bottom=n-1;

        spiralRec(left,right,top,bottom,matrix,v);
        return v;
    }
};