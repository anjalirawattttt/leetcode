class Solution {
public:
    void help(int top,int bottom,int left,int right,vector<int>& ans,vector<vector<int>>& matrix){
        if(top>bottom || left>right)return;
        //right
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        //bottom
        if(top<=bottom){
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
        }
        else{
            return;
        }

        //left
        if(left<=right){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        

        //top
        if(left<=right && top<=bottom){
            for(int j=bottom;j>=top;j--){
                ans.push_back(matrix[j][left]);
            }
            left++;
        }
        

        help(top,bottom,left,right,ans,matrix);

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        help(0,m-1,0,n-1,ans,matrix);
        return ans;   
    }
};