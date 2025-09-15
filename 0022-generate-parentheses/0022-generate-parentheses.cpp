class Solution {
public:
    void help(string temp,vector<string>& v,int n,int open){
        if(n==0 && open==0){
            v.push_back(temp);
            return;
        }
        if(n>0){
            //'('
            temp+='(';
            help(temp,v,n-1,open+1);
            temp.pop_back();
        }
        if(open>0){
            //')'
            temp+=')';
            help(temp,v,n,open-1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        help("",v,n,0);
        return v;   
    }
};