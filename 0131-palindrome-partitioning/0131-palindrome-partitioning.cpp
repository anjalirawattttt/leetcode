class Solution {
public:
    bool check(string s ,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        } 
        return true;   
    }

    void help(vector<vector<string>>& res,vector<string> temp,string s,int i){
        if(i==s.length()){
            res.push_back(temp);
            return;
        }

        for(int j=i;j<s.length();j++){
            if(check(s,i,j)){
                string sub=s.substr(i, j - i + 1);
                temp.push_back(sub);
                help(res,temp,s,j+1);
                temp.pop_back();
            }
        }


    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        help(res,temp,s,0);
        return res;  
    }
};