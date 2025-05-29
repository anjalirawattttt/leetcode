class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int>& nums,int i,vector<int> subset,set<vector<int>> &s){
        if(i==nums.size()){
            if(s.find(subset)==s.end()){
                ans.push_back(subset);
                s.insert(subset);
            }
            return;
        }
        helper(ans,nums,i+1,subset,s);
        subset.push_back(nums[i]);
        helper(ans,nums,i+1,subset,s);
        subset.pop_back();

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        helper(ans,nums,0,{},s);
        return ans;   
    }
};