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
        // take
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            help(temp,v,candidates,target-candidates[i],i+1);
            temp.pop_back();
        }
        //not take
        while(i<candidates.size()-1 && candidates[i]==candidates[i+1])i++;
        help(temp,v,candidates,target,i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> v;
        help({},v,candidates,target,0);
        return v;  
    }
};