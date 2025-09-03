class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            int x=1;
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1){
                    temp.push_back(1);
                    continue;
                }
                x*=i-j;
                x/=j;
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;   
    }
};