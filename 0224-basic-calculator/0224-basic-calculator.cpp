class Solution {
public:
    int calculate(string s) {
        int ans=0;
        stack<int> st;
        int num=0,sign=1;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(isdigit(c)){
                num=num*10+ (c-'0');
            }
            else if(c=='+'){
                ans+=num*sign;
                num=0;
                sign=1;
            }
            else if(c=='-'){
                ans+=num*sign;
                num=0;
                sign=-1;
            }
            else if(c=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }
            else if(c==')'){
                ans+=num*sign;
                sign=1;
                num=0;
                ans*=st.top();st.pop();
                ans+=st.top();st.pop();
            }
        }
        ans+=num*sign;
        return ans;       
    }
};