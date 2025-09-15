class Solution {
public:
    long long help(int i,string s,long long ans){
        if(i>=s.length())return ans;
        if(s[i]>='0' && s[i]<='9'){
            int num=s[i]-'0';
            if(ans < (LONG_MAX-num)/10 ){
                ans= (ans*10) + (num) ;
            }
            else return LONG_MAX;
            return help(i+1,s,ans);
        }
        return ans;
    }
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        //leading whitespaces
        while(i<n && s[i]==' ')i++;
        //sign
        bool flag=true;
        if(i<n && s[i]=='-'){
            flag=false;
            i++;
        }
        else if(i<n && s[i]=='+'){
            flag=true;
            i++;
        }
        //number
        while(i<n && s[i]=='0')i++;
        long long ans=help(i,s,0);
        if(!flag)ans=-1*ans;
        if(ans>INT_MAX)ans=INT_MAX;
        else if(ans<INT_MIN)ans=INT_MIN;
        return (int)ans;
    }
};