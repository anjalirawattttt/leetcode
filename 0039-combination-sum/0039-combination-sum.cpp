class Solution {
public:
    void help(vector<int> temp,vector<vector<int>>& ans,int i,vector<int>& candidates,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size()){
            return;
        }
        //take
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            help(temp,ans,i,candidates,target-candidates[i]);
            temp.pop_back();
        }
        //not take
        help(temp,ans,i+1,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        help({},ans,0,candidates,target);
        return ans;
    }
};