class Solution {
public:
    void help(vector<int> temp,vector<vector<int>>& v,int n,int target,int num){
        if(target==0 && n==0){
            v.push_back(temp);
            return;
        }
        if(n==0 || target<0 || num>9)return;
        //take
        temp.push_back(num);
        help(temp,v,n-1,target-num,num+1);
        temp.pop_back();
        //not take
        help(temp,v,n,target,num+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        help({},v,k,n,1);
        return v;    
    }
};