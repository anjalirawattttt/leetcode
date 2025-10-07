class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_set<string> st;
        int i=0,j=0;
        string temp="";
        while(j<s.length()){
            if(s[j]==' '){
                char c=pattern[i];
                if(m.find(c)==m.end()){
                    if(st.find(temp)==st.end()){                
                        m[c]=temp;
                        st.insert(temp);
                    }
                    else return false;
                }
                else if(temp!=m[c])return false;
                temp.clear();
                i++;
            }
            else{
                temp+=s[j];
            }
            j++;
        } 
        char c=pattern[i];
        i++;
        if(m.find(c)==m.end()){
            if(st.find(temp)==st.end()){                
                m[c]=temp;
                st.insert(temp);
            }
            else return false;
        }
        else if(temp!=m[c])return false;  

        return i==pattern.length();
    }
};