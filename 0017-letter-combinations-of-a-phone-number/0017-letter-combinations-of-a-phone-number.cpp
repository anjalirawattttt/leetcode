class Solution {
public:
    void helper(vector<string> &ans,string digits,int i,vector<string> &map,string temp){
        
        if(i==digits.length()){
            ans.push_back(temp);
            return;
        }

        int digit=digits[i] - '0';

        for(int j=0;j<map[digit].size();j++){
            temp+=map[digit][j];
            helper(ans,digits,i+1,map,temp);
            temp.pop_back();   
        }
    }
    

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> ans;
        vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(ans,digits,0,map,"");
        return ans;    
    }
};