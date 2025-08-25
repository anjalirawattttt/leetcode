class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> m;
        int temp=0,ans=0;
        int l=0,r=0;

        while(l<n && r<n){
            if(m[s[r]]==0){
                m[s[r]]=1;
                temp++;
                r++;
            }
            else{
                while(l<n && m[s[r]]!=0){
                    m[s[l]]--;
                    l++;
                    temp--;
                }
                // m[s[r]]=1;
                // temp++;
            }
            ans=max(ans,temp);
        }
        
        
        return ans;   
    }
};