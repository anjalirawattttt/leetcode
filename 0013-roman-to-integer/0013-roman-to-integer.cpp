class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i<s.length()-1 && m[s[i]]<m[s[i+1]]){
                ans+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else{
                ans+=m[s[i]];
            }
        } 
        return ans;
    }
};