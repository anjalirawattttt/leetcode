class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        int num=0,sign=1,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')continue;
            if(s[i]=='+'){
                ans+=num*sign;
                num=0;
                sign=1;
            }
            else if(s[i]=='-'){
                ans+=num*sign;
                num=0;
                sign=-1;
            }
            else if(s[i]=='*'){
                s1.push(num);
                num=0;
                while(s[i+1]==' ')i++;
                while(isdigit(s[i+1])){
                    num=num*10+(s[i+1]-'0');
                    i++;
                }
                int temp=s1.top();
                s1.pop();   
                num=temp*num;             
            }
            else if(s[i]=='/'){
                s1.push(num);
                num=0;
                while(s[i+1]==' ')i++;
                while(isdigit(s[i+1])){
                    num=num*10+(s[i+1]-'0');
                    i++;
                }
                int temp=s1.top();
                s1.pop();   
                num=temp/num;
            }
            else{
                num=num*10+(s[i]-'0');
            }
        }
        ans+=num*sign;
        return ans;   
        
        
    }
};