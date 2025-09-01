class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int n=s.length();
        int left=0,right=0;
        int i=0;
        for(int j=0;j<n;j++){
            if(s[j]=='(')left++;
            else right++;
            if(left==right){
                ans+=s.substr(i+1,j-i-1);
                i=j+1;
            }  
        }
        
        return ans;
    }
};