class Solution {
public:
    void help(int open,int n,vector<string> &ans,string temp){
        if(open==0 && n==0){
            ans.push_back(temp);
            return;
        }
        //open
        if(n>0){
            help(open+1,n-1,ans,temp+"(");
        }
        //close
        if(open>0){
            help(open-1,n,ans,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(0,n,ans,"");
        return ans;    
    }
};