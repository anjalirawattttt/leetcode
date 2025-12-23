class Solution {
public:
    void help(vector<int> &ans,int top,int bottom,int left ,int right,vector<vector<int>> &matrix){
        if(top>bottom || left>right)return;
        for(int j=left;j<=right;j++){
            ans.push_back(matrix[top][j]);
        }
        top++;

        if(top<=bottom && left<=right){
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
        }

        if(top<=bottom && left<=right){
            for(int j=right;j>=left;j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(top<=bottom && left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            
            left++;
        }

        help(ans,top,bottom,left,right,matrix);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        help(ans,0,m-1,0,n-1,matrix);
        return ans;    
    }
};