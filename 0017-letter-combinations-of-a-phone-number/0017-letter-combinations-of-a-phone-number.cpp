class Solution {
public:
    void helper(vector<string>& res,string &temp,string digits,int i,unordered_map<char,string> m){
        if(i==digits.length()){
            res.push_back(temp);
            return;
        }
        
        for(int k=0;k<m[digits[i]].length();k++){
            temp+=m[digits[i]][k];
            helper(res,temp,digits,i+1,m);
            temp.pop_back();
        }
    }
    
    

    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.length()==0)return res;
        string temp;
        unordered_map<char,string> m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        helper(res,temp,digits,0,m);
        return res;    
    }
};