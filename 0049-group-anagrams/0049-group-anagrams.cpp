class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        vector<vector<string>> result;
        for(string &s:strs){
            vector<int> freq(26,0);
            for(char &c:s){
                freq[c-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+='#';
                key+=to_string(freq[i]);
            }
            hash[key].push_back(s);
        }
        for(auto &p:hash){
            result.push_back(p.second);
        }
        return result;  
    }
};