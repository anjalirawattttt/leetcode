class Solution {
public:
    void reverse(string &s,int start,int end){
        int l=start;
        int r=end;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    void reverse(string &s){
        int l=0;
        int r=s.length()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }

    string reverseWords(string s) {
        int n=s.length();
        string ans;

        int i=0,j=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i]!=' ')s[j++]=s[i++];
            while(i<n && s[i]==' ')i++;
            if(i<n)s[j++]=' ';
        }
        s.resize(j);
        reverse(s,0,s.length()-1);

        int start=0;
        for(int end=0;end<=s.length();end++){
            if(end==s.length() || s[end]==' '){
                reverse(s,start,end-1);
                start=end+1;
            }
        }
        return s;
    }
};