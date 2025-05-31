class Solution {
public:
    void helper(vector<string> &ans,string &digits,int i,unordered_map<char,string> &map,string temp){
        
        if(i==digits.length()){
            ans.push_back(temp);
            return;
        }

        

        for(int j=0;j<map[digits[i]].size();j++){
            temp+=map[digits[i]][j];
            helper(ans,digits,i+1,map,temp);
            temp.pop_back();   
        }
    }
    

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> ans;
        unordered_map<char,string> map={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        helper(ans,digits,0,map,"");
        return ans;    
    }
};