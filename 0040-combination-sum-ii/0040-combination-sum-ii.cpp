class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& temp,vector<int>& candidates,int target,int i,int sum){
        if(sum==target){
            res.push_back(temp);
            return;
        }
        if(i==candidates.size() || sum>target)return;
        temp.push_back(candidates[i]);
        helper(res,temp,candidates,target,i+1,sum+candidates[i]);
        temp.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1])i++;
        helper(res,temp,candidates,target,i+1,sum);
    }
   

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(res,temp,candidates,target,0,0);
        return res;

    }
};