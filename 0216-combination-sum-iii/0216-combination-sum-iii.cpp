class Solution {
public:

    void helper(int k,int n,vector<vector<int>>& ans,vector<int>& subset,int pos){
        if(n==0 && k==0){
            ans.push_back(subset); 
            return;   
        }
        if(pos>9)return;
        if( k<0 || n<0 )return;
        if(9-pos+1<k)return;
        subset.push_back(pos);
        helper(k-1,n-pos,ans,subset,pos+1);  
        subset.pop_back(); 
        helper(k,n,ans,subset,pos+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(k,n,ans,subset,1);
        return ans;   
    }

};