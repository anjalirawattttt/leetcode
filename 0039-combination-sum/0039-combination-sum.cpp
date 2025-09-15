class Solution {
public:
    void help(vector<int> temp,vector<vector<int>>& v,vector<int>& candidates,int target,int i,set<vector<int>> &s){
        if(target==0){
            if(s.find(temp)!=s.end())return;
            s.insert(temp);
            v.push_back(temp);
            return;
        }
        if(i>=candidates.size()){
            return;   
        }
        //not take
        help(temp,v,candidates,target,i+1,s);
        // take
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            help(temp,v,candidates,target-candidates[i],i,s);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        set<vector<int>> s;
        help({},v,candidates,target,0,s);
        return v;   
    }
};