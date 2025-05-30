class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& candidates,int target,vector<int>& subset,int pos){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(target<0)return;
        if(pos>=candidates.size())return;

        
        subset.push_back(candidates[pos]);
        helper(ans,candidates,target-candidates[pos],subset,pos+1);
        subset.pop_back();
        while(pos+1<candidates.size() && candidates[pos]==candidates[pos+1])pos++;
        helper(ans,candidates,target,subset,pos+1);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<vector<int>> ans;
     vector<int> subset;
     sort(candidates.begin(),candidates.end());
     helper(ans,candidates,target,subset,0);
     sort(ans.begin(),ans.end());
     return ans;   
    }
};