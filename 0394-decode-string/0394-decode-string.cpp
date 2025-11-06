class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<string> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                string temp="";
                temp+=s[i];
                while(i<n-1 && isalpha(s[i+1])){
                    temp+=s[i+1];
                    i++;
                }
                st.push(temp);
            }
            else if(isdigit(s[i])){
                string temp="";
                temp+=s[i];
                while(i<n-1 && isdigit(s[i+1])){
                    temp+=s[i+1];
                    i++;
                }
                st.push(temp);
            }
            else if(s[i]=='['){
                st.push("[");
            }
            else if(s[i]==']'){
                //string
                string str="";
                while(st.top()!="["){
                    str=st.top()+str;
                    st.pop();
                }
                string temp=st.top();
                st.pop();
                if(temp!="[")return "";
                string num=st.top();
                st.pop();
                int number=stoi(num);
                temp="";
                for(int i=0;i<number;i++){
                    temp+=str;
                }
                // if(st.empty() || st.top()=="["){
                //     st.push(temp);
                // }
                // else{
                //     temp=st.top()+temp;
                //     st.pop();
                    st.push(temp);
                // }
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};