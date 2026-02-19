class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int i=0,n=s.length();
        while(i<n){
            int zeroes=0,ones=0;
            while(i<n && s[i]=='0'){
                zeroes++;
                i++;
            }
            while(i<n && s[i]=='1'){
                ones++;
                i++;
            }
            int mini=min(ones,zeroes);
            ans+=mini;
        }  
        i=0;
        while(i<n){
            int zeroes=0,ones=0;
            while(i<n && s[i]=='1'){
                ones++;
                i++;
            }
            while(i<n && s[i]=='0'){
                zeroes++;
                i++;
            }
            int mini=min(ones,zeroes);
            ans+=mini;
        }
        return ans;
    }
};