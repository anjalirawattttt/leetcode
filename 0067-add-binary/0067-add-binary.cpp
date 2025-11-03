class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.length(),n2=b.length();
        if(n2>n1)return addBinary(b,a);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int i=0,j=0;
        string ans="";
        while(i<n1 && j<n2){
            if(carry){
                if((a[i]=='0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
                    ans+='0';
                }
                else if(a[i]=='0' && b[i]=='0'){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='1';
                }
            }
            else{
                if((a[i]=='0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
                    ans+='1';
                }
                else if(a[i]=='0' && b[i]=='0'){
                    ans+='0';
                }
                else{
                    ans+='0';
                    carry=1;
                }
            }
            i++;
            j++;
        }

        while(i<n1){
            if(carry){
                if(a[i]=='0'){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
            else{
                ans+=a[i];
            }
            i++;
        }

        if(carry)ans+='1';

        reverse(ans.begin(),ans.end());
        return ans;
    }
};