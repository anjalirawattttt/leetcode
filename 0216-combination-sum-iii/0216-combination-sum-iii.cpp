class Solution {
public:
    void helper(int k,int n,vector<vector<int>>& res,vector<int>& temp,int i,int sum){
        if(sum==n && temp.size()==k){
            res.push_back(temp);
            return;
        }
        if(sum>n || i>9 || temp.size()>k)return;
        temp.push_back(i);
        helper(k,n,res,temp,i+1,sum+i);
        temp.pop_back();
        helper(k,n,res,temp,i+1,sum);
    }
    

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(k,n,res,temp,1,0);
        return res;    
    }

};