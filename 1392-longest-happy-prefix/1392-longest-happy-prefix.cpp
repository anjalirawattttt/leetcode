class Solution {
public:
    vector<int> buildLPS(string &pat){
        int n=pat.size();
        vector<int> lps(n,0);
        int len=0;

        for(int i=1;i<n;i++){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                    //to stop i from incrementing
                    i--;
                }
                else{
                    len=0;
                }
            }
        }

        return lps;
    }
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> lps=buildLPS(s);
        int len=lps[n-1];
        return s.substr(0,len);  
    }
};