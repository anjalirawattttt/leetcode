class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int na=a.size(),nb=b.size();
        int ia=0,ib=0;
        int carry=0;
        string ans="";
        while(ia<na && ib<nb){
            if(a[ia]=='1' && b[ib]=='1'){
                if(carry){
                    ans+='1';
                    carry=1;
                }
                else{
                    ans+='0';
                    carry=1;
                }
            }
            else if((a[ia]=='1' && b[ib]=='0') || (a[ia]=='0' && b[ib]=='1')){
                if(carry){
                    ans+='0';
                    carry=1;
                }
                else{
                    ans+='1';
                    carry=0;
                }
            }
            else{
                if(carry){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                    carry=0;
                }
            }
            ia++;
            ib++;
        }

        while(ia<na){
            if(a[ia]=='1'){
                if(carry){
                    ans+='0';
                    carry=1;
                }
                else{
                    ans+='1';
                    carry=0;
                }
            }
            else{
                if(carry){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
            ia++;
        }  

        while(ib<nb){
            if(b[ib]=='1'){
                if(carry){
                    ans+='0';
                }
                else{
                    ans+='1';
                }
            }
            else{
                if(carry){
                    ans+='1';
                    carry=0;
                }
                else{
                    ans+='0';
                }
            }
            ib++;
        } 
        if(carry)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};