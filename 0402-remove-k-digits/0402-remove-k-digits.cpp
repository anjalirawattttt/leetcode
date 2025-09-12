class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<int> s;
        int n=num.length();
        if(k==n)return "0";

        for(int i=0;i<n;i++){
            int x=num[i]-'0';
            while(k>0 && !s.empty() && s.top()>x){
                s.pop();
                k--;
            }
            s.push(x);            
        }
        while(k>0){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        string res="";
        for(int i=0;i<ans.length();i++){
            if(res=="" && ans[i]=='0')continue;
            res+=ans[i];
        }
        return res==""?"0":res;   
    }
};