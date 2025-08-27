class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int totalSubsets=1<<n;
        vector<vector<int>> ans(totalSubsets);
        for(int i=0;i<totalSubsets;i++){
            for(int j=0;j<n;j++){
                if(1&(i>>j))ans[i].push_back(nums[j]);
            }
        } 
        return ans;   
    }
};