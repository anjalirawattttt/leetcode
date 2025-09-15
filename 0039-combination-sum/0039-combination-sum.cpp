class Solution {
public:
    void help(vector<int> temp,vector<vector<int>>& v,vector<int>& candidates,int target,int i){
        if(target==0){
            v.push_back(temp);
            return;
        }
        if(i>=candidates.size()){
            return;   
        }
        //not take
        help(temp,v,candidates,target,i+1);
        // take
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            help(temp,v,candidates,target-candidates[i],i);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        help({},v,candidates,target,0);
        return v;   
    }
};