class Solution {
public:
    int maxDepth(string s) {
        int left=0,right=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')left++;
            else if(s[i]==')')right++;
            ans=max(ans,left-right);
        }
        return ans;
    }
};