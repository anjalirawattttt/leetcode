class Solution {
public:
    string shortestPalindrome(string s) {
        //using KMP
        int n=s.length();

        string rev=s;
        reverse(rev.begin(),rev.end());

        string temp=s+"-"+rev;
        int size=2*n+1;

        vector<int> lps(size,0);
        int len=0;
        int i=1;
        while(i<size){
            if(temp[i]==temp[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else if(len>0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
        int pal=lps[size-1]; 
        int rem=n-pal;
        return rev.substr(0,rem)+s;
    }
};