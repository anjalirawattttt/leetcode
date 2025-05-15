class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans;
        int start,end;
        int maxx=INT_MIN;
        int length;

        for(int i=0;i<n;i++){
            //even expansion
            int j=i;
            int k=i;
            while(j>=0 && k<n && s[j]==s[k] ){
                j--;
                k++;
            }
            j++;
            k--;
            length=k-j+1;
            if(length>maxx){
                maxx=length;
                start=j;
                end=k;
            }
            //odd expansion
            j=i;
            k=i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                j--;
                k++;
            }
            j++;
            k--;
            length=k-j+1;
            if(length>maxx){
                maxx=length;
                start=j;
                end=k;
            } 
        } 
        

        int i=start;
        while(i!=end){
            ans+=s[i];
            i++;
        }
        ans+=s[i];

        return ans;
    }
};