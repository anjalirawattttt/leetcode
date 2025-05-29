class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& nums,int pos){       
        if(pos==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=pos;i<nums.size();i++){
            if(used.find(nums[i])!=used.end())continue;
            used.insert(nums[i]);
            swap(nums[pos],nums[i]);
            helper(ans,nums,pos+1);
            swap(nums[pos],nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(ans,nums,0);
        return ans;  
    }
};