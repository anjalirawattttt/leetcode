class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int>& nums,int i,vector<int> subset){
        ans.push_back(subset);                
            
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])continue;
            subset.push_back(nums[j]);
            helper(ans,nums,j+1,subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(ans,nums,0,{});
        return ans;   
    }
};