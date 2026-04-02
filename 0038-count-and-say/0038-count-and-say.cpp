class Solution {
public:
    string help(string s){
        string ans="";
        int i=0,n=s.length();
        while(i<n){
            char c=s[i];
            int temp=i;
            while(i<n-1 && s[i+1]==c)i++;
            int length = i-temp+1;
            ans+=to_string(length);
            ans+=c;
            i++;
        }
        return ans;
    }
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++){
            // cout<<s<<endl;
            s=help(s);
        } 
        // cout<<s<<endl;
        return s;   
    }
};