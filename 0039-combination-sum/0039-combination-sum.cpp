class Solution {
public:
    void helper(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &subset,int pos){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(target<0)return;
        if(pos>=candidates.size())return;
        subset.push_back(candidates[pos]);
        helper(candidates,target-candidates[pos],ans,subset,pos);
        subset.pop_back();
        helper(candidates,target,ans,subset,pos+1);  
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(candidates,target,ans,subset,0);
        return ans;    
    }
};