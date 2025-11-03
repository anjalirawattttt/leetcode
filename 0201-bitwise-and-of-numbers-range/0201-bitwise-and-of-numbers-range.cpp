class Solution {
public:
    string to_binary(int num){
        string temp="";
        while(num>0){
            if(num%2==1){
                temp+='1';
            }
            else{
                temp+='0';
            }
            num/=2;
        }
        int n=temp.length();
        reverse(temp.begin(),temp.end());
        return string(31-n,'0')+temp;
    }
    int to_number(string s){
        int ans=0;
        for(char &c:s){
            ans=(ans<<1)+(c-'0');
        }
        return ans;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==0)return 0;
        string l=to_binary(left);
        string r=to_binary(right);

        string ans="";
        bool same=true;
        for(int i=0;i<31;i++){
            if(l[i]==r[i]){
                ans+=l[i];
            }
            else{
                ans+=string(31-i,'0');
                break;
            }
        }

        int result=to_number(ans);
        return result;
    }
};