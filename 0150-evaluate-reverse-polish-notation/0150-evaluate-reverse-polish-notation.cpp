class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="/" || tokens[i]=="-"){
                
                    if(tokens[i]=="+"){
                        int y=s.top();
                        s.pop();
                        int x=s.top();
                        s.pop();
                        int z=x+y;
                        s.push(z);
                        
                    }
                    else if(tokens[i]=="*"){
                        int y=s.top();
                        s.pop();
                        int x=s.top();
                        s.pop();
                        int z=x*y;
                        s.push(z);
                        
                    }
                    else if(tokens[i]=="-"){
                        int y=s.top();
                        s.pop();
                        int x=s.top();
                        s.pop();
                        int z=x-y;
                        s.push(z);
                        
                    }
                    else if(tokens[i]=="/"){
                        int y=s.top();
                        s.pop();
                        int x=s.top();
                        s.pop();
                        int z=x/y;
                        s.push(z);
                        
                    }
                
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }  
        return s.top();   
    }
};