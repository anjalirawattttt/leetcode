class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;

        //ignore leading whitespaces
        while(i<n && s[i]==' ')i++;
        
        //sign
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-')sign=-1;
            i++;
        }

        //ignore leading zeroes
        //end at non digit or end of string
        int ans=0;
        while(i<n && isdigit(s[i])){
            int num=s[i]-'0';
            if( ans > (INT_MAX-num)/10 ){
                return sign==1?INT_MAX:INT_MIN;
            }
            ans=ans*10+num;
            i++;
        }

        return (ans*sign);
    }
};