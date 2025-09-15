class Solution {
public:
    void help(vector<int> temp,vector<vector<int>>& ans,int i,vector<int>& nums){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //take
        temp.push_back(nums[i]);
        help(temp,ans,i+1,nums);
        temp.pop_back();
        //not take
        help(temp,ans,i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        help({},ans,0,nums);
        return ans;    
    }
};