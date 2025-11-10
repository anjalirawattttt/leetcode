class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word="";
        for(char &ch:s){
            if(ch==' '){
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
            }
            else{
                word+=ch;
            }
        }
        if(!word.empty()){
            words.push_back(word);
            word.clear();
        }    
        string ans="";
        reverse(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            if(i==0)ans+=words[i];
            else ans+=" "+words[i];
        }
        return ans;
    }
};