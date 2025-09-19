class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& temp,vector<int>& candidates,int target,int i,int sum){
        if(sum==target){
            res.push_back(temp);
            return;
        }
        if(i==candidates.size() || sum>target)return;
        temp.push_back(candidates[i]);
        helper(res,temp,candidates,target,i,sum+candidates[i]);
        temp.pop_back();
        helper(res,temp,candidates,target,i+1,sum);
    }
   

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,temp,candidates,target,0,0);
        return res;

    }
};