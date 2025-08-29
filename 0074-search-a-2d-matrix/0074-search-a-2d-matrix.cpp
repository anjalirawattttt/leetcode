class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,h=m-1;
        int r=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                r=mid;
                break;
            }
            else if(target<matrix[mid][0]){
                h=mid-1;
            }
            else if(target>matrix[mid][n-1]){
                l=mid+1;
            }
        } 
        if(r==-1)return false;
        l=0;h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(matrix[r][mid]==target)return true;
            else if(matrix[r][mid]>target)h=mid-1;
            else l=mid+1;
        } 
        return false;  
    }
};