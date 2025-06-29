class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& res,int pos){        if(pos==nums.size()){
        res.push_back(nums);
        return;
    }
        unordered_set<int> used;
        for(int i=pos;i<nums.size();i++){
            if(used.find(nums[i])!=used.end())continue;
            used.insert(nums[i]);
            swap(nums[i],nums[pos]);
            helper(nums,res,pos+1);
            swap(nums[i],nums[pos]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        helper(nums,res,0);
        return res; 
    }
};