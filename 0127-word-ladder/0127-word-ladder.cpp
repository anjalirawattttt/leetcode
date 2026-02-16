class Solution {
public:
    int help (string &word, string &endWord,unordered_set<string> &words){
        if(word==endWord)return 1;
        int ans=1e7;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            for(char ch='a';ch<='z';ch++){
                if(ch==c)continue;
                word[i]=ch;
                if(words.find(word)!=words.end()){
                    words.erase(word);
                    ans=min(ans,1+help(word,endWord,words));
                    words.insert(word);
                }
            }
            word[i]=c;
        }
        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if(words.find(endWord)==words.end())return 0;

        
        queue< pair<string,int> > q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++){
                char c=word[i];
                for(char ch='a';ch<='z';ch++){
                    if(ch==c)continue;
                    word[i]=ch;
                    if(words.find(word)!=words.end()){
                        words.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=c;
            }

        }
        return 0; 

    }
};