class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int>& nums,int i,vector<int> subset){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }
        helper(ans,nums,i+1,subset);
        subset.push_back(nums[i]);
        helper(ans,nums,i+1,subset);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans,nums,0,{});
        return ans;    
    }
};