class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans(n);
        for(int j=0;j<n;j++){
            int maxLen=0;
            for(int i=0;i<m;i++){
                int num=grid[i][j];
                string s=to_string(num);
                int size=s.length();
                maxLen=max(maxLen,size);
            }
            ans[j]=maxLen;
        } 
        return ans;   
    }
};