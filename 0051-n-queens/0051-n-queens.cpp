class Solution {
public:
    void help(vector<string> &temp,vector<vector<string>> &ans,int n,int i,unordered_set<int> &cols,unordered_set<int> &leftDiag,unordered_set<int> &rightDiag){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
                if(cols.find(j)==cols.end() && leftDiag.find(i+j)==leftDiag.end() && rightDiag.find(i-j)==rightDiag.end()){
                    cols.insert(j);
                    leftDiag.insert(i+j);
                    rightDiag.insert(i-j);
                    temp[i][j]='Q';
                    help(temp,ans,n,i+1,cols,leftDiag,rightDiag);
                    temp[i][j]='.';
                    cols.erase(j);
                    leftDiag.erase(i+j);
                    rightDiag.erase(i-j);
                }
            }

    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.')); 
        unordered_set<int> cols;
        unordered_set<int> leftDiag;
        unordered_set<int> rightDiag;
        help(temp,ans,n,0,cols,leftDiag,rightDiag);
        return ans;
    }
};