class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string &word:wordList){
            s.insert(word);
        }   

        if(s.find(endWord)==s.end())return 0;

        queue<pair<string,int>> q;//word+steps
        q.push({beginWord,1});
        while(!q.empty()){
            auto[word,steps]=q.front();
            q.pop();
            if(word==endWord)return steps;

            for(int i=0;i<word.length();i++){
                string temp=word;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(s.find(temp)!=s.end()){
                        q.push({temp,steps+1});
                        s.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};