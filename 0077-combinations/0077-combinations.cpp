class Solution {
public:
    void helper(int n,int k,vector<vector<int>>& ans,vector<int> subset,int pos){
        if(k==0){
            ans.push_back(subset);
            return;                
        }
        if(pos>n){
            return;   
        }
        if(n-pos+1 < k){
            return;
        }
        helper(n,k,ans,subset,pos+1);
        subset.push_back(pos);
        helper(n,k-1,ans,subset,pos+1);
        subset.pop_back();

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        helper(n,k,ans,{},1);
        return ans;   
    }
};