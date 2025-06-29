class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>> &res,vector<int>& temp,int i){
        res.push_back(temp);
        if(i==nums.size()){
            return;
        }
        
        
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])continue;
            temp.push_back(nums[j]);
            helper(nums,res,temp,j+1);
            temp.pop_back();
        }
    }
    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums,res,temp,0);
        return res;  
    }
};