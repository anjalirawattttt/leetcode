class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int rl=0,rh=m-1;
        int cl=0,ch=n-1;
        while(rl<=rh && cl<=ch){
            int rmid = rl + (rh-rl)/2;
            int cmid = cl + (ch-cl)/2;
            if(matrix[rmid][cmid]==target)return true;
            else if(matrix[rmid][cmid]<target){
                if(matrix[rmid][n-1]<target){
                    rl=rmid+1;
                    cl=0;
                    ch=n-1;
                }
                else{
                    cl=cmid+1;
                }
            } 
            else{
                //>
                if(matrix[rmid][0]>target){
                    rh=rmid-1;
                    cl=0;
                    ch=n-1;
                }
                else{
                    ch=cmid-1;
                }
            }
        }
        return false;

        
    }
};