class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> m={           
             {'(',-1}
            ,{')',1}
            ,{'{',-2}
            ,{'}',2}
            ,{'[',-3}
            ,{']',3}
        }; 
        stack<int> st;
        for(char& ch:s){
            if(st.empty() && m[ch]>0)return false;
            if(m[ch]>0){
                if( st.top()==(-1*m[ch]) )st.pop();
                else return false;
            }
            else{
                st.push(m[ch]);
            }
        }  
        return st.empty();
    }
};