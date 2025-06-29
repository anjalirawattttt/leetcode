class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>> &res,vector<int>& temp,int i){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        helper(nums,res,temp,i+1);
        temp.push_back(nums[i]);
        helper(nums,res,temp,i+1);
        temp.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums,res,temp,0);
        return res;     
    }
};