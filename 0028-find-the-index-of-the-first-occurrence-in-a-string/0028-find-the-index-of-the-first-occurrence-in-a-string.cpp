class Solution {
public:
    bool match(string txt,string pat,int q=11){
        int d=256;
        int n=txt.length();
        int m=pat.length();
        if(m>n)return false;

        int t=0,p=0;
        int h=1;
        // d^m-1
        for(int i=0;i<m-1;i++){
            h = (h*d) % q;
        }

        for(int i=0;i<m;i++){
            t = ( t*d + txt[i]) % q ;
            p = ( p*d + pat[i]) % q ;
        }

        for(int i=0;i<=n-m;i++){
            if(p==t){
            int j;
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j])break;
            }
            if(j==m)return true;
            }
            if(i<n-m){
            t = ( (t-txt[i]*h)*d + txt[i+m] )  % q ;
            if(t<0)t+=q;
            }
        }

        return false;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m>n)return -1;
        for(int i=0;i<=n-m;i++){
            string temp=haystack.substr(i,m);
            if(match(temp,needle))return i;
        }  
        return -1;  
    }
};