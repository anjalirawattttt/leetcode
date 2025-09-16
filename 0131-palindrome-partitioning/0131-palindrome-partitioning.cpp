class Solution {
public:
    bool isPalindrome(string &s){
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void help(string str,vector<string> temp,vector<vector<string>>& ans,string s,int i){
        if(i>=s.length()){
            if(str.empty()){
                ans.push_back(temp);
            }
            return;
        }
        str+=s[i];
        //take
        if(isPalindrome(str)){
            temp.push_back(str);
            string sTemp=str;
            str.clear();

            help(str,temp,ans,s,i+1);

            str=sTemp;
            temp.pop_back();
        }
        //not take
        help(str,temp,ans,s,i+1);
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        help("",temp,ans,s,0);
        return ans;
    }
};