class Solution {
public:
    void helper(int n,int k,vector<vector<int>>& res,vector<int>& temp,int i){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        if(i>n){
            return;
        }
        temp.push_back(i);
        helper(n,k,res,temp,i+1);
        temp.pop_back();
        helper(n,k,res,temp,i+1);

    }
    

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(n,k,res,temp,1);
        return res;  
    }
};