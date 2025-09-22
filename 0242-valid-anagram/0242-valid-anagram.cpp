class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int> hash(26,0);
        for(char &ch : s){
            hash[ch-'a']++;
        }  
        for(char &ch : t){
            hash[ch-'a']--;
            if(hash[ch-'a']<0)return false;
        }
        return true;
    }
};