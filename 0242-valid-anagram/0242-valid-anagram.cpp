class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;

        unordered_map<char,int> m;
        
        for(char &ch:s){
            m[ch]++;
        } 
        for(char &ch:t){
            m[ch]--;
        } 
        for(auto &[k,v]:m){
            if(v!=0)return false;
        } 
        return true; 
    }
};