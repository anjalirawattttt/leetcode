class Solution {
public:
    void help(int top,int bottom,int left ,int right,vector<int>& ans,vector<vector<int>>& matrix){
        if(top>bottom || left>right)return;

        //left to right
        for(int j=left;j<=right;j++){
            ans.push_back(matrix[top][j]);
        }
        top++;
        if(top>bottom)return;


        if(top<=bottom){
            //top to bottom
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);    
            }
            right--;
        }

        if(left<=right){
            //right to left
            for(int j=right;j>=left;j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(top<=bottom && left<=right){
            //bottom to top
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);    
            }
            left++;
        }
        help(top,bottom,left,right,ans,matrix);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        help(0,m-1,0,n-1,ans,matrix);
        return ans;    
    }
};