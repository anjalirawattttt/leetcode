class Solution {
public:
    void help(int top,int bottom,int left,int right,vector<vector<int>> &matrix,vector<int>& ans){
        if(left>right || top>bottom)return;
        //left to right
        for(int j=left;j<=right;j++){
            ans.push_back(matrix[top][j]);
        }
        top++;
        //top to bottom
        if(top<=bottom){
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
        }
        //right to left
        if(top<=bottom && left<=right){
            for(int j=right;j>=left;j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        //bottom to top
        if(top<=bottom && left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        help(top,bottom,left,right,matrix,ans);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        help(0,m-1,0,n-1,matrix,ans);
        return ans;    
    }
};