class Solution {
public:
    void help(string temp,vector<string>& ans,int i,string &digits,unordered_map<int,string> &m){
        if(i>=digits.length()){
            if(temp!="")ans.push_back(temp);
            return;
        }
        string mapped=m[ digits[i]-'0' ];
        for(int j=0;j<mapped.length();j++){
            temp+=mapped[j];
            help(temp,ans,i+1,digits,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<int,string> m={
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"}
        };
        help("",ans,0,digits,m);
        return ans;    
    }
};