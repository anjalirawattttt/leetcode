class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for(int i=0;i<expression.length();i++){
            if( expression[i]=='&' || expression[i]=='|' || expression[i]=='!' ){
                s.push(expression[i]);
            }
            else if( expression[i]=='t' || expression[i]=='f' ){
                s.push(expression[i]);
            }
            else if(expression[i]==')'){
                // cout<<"hi";
                bool allTrue=true;
                bool oneTrue=false;
                while(!s.empty() && s.top()!='&' && s.top()!='|' && s.top()!='!' ){
                    if(s.top()=='f')allTrue=false;
                    if(s.top()=='t')oneTrue=true;
                    // cout<<s.top();
                    s.pop();
                }
                // cout<<s.top();
                if(!s.empty()){
                    // cout<<s.top();
                    if(s.top()=='&'){
                        s.pop();
                        if(allTrue){
                            s.push('t');
                        }
                        else{
                            s.push('f');
                        }
                    }
                    else if(s.top()=='|'){
                        s.pop();
                        if(oneTrue){
                            s.push('t');
                        }
                        else{
                            s.push('f');
                        }
                    }
                    else if(s.top()=='!'){
                        s.pop();
                        if(allTrue){
                            s.push('f');
                        }
                        else{
                            s.push('t');
                        }
                    }
                }
            }
        } 
        return s.top()=='t'?true:false;   
    }
};