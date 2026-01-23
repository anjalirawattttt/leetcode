class Solution {
public:
    void help(vector<string> &temp,vector<vector<string>> &path,map<string,vector<string>> &parent,string beginWord,string endWord,int ans){
        if(ans<0)return;
        if(endWord==beginWord){
            path.push_back(temp);
            return;
        }
        for(string &s:parent[endWord]){
            temp.push_back(s);
            help(temp,path,parent,beginWord,s,ans-1);
            temp.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> path;

        if(beginWord.length() != endWord.length())return path;
        map<string,vector<string>> parent;
        set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }

        if(s.find(endWord)==s.end())return path;

        //bfs
        int ans=0;
        int moves=1;
        queue<string> q;
        q.push(beginWord);
        if(s.find(beginWord)!=s.end())s.erase(beginWord);
        while(!q.empty()){
            int size=q.size();
            set<string> visitedThisLevel;
            while(size--){
                string str=q.front();
                string curr=str;
                q.pop();
                if(curr==endWord){
                    ans=moves;
                }
                for(int i=0;i<curr.length();i++){
                    char temp=curr[i];
                    for(char c='a';c<='z';c++){
                        if(temp==c)continue;
                        curr[i]=c;
                        if(s.find(curr)!=s.end()){
                            parent[curr].push_back(str);
                            if(visitedThisLevel.find(curr)==visitedThisLevel.end()){
                                visitedThisLevel.insert(curr);
                                q.push(curr);
                            }
                        }
                    }
                    curr[i]=temp;
                }
            }
            for(auto &st:visitedThisLevel)s.erase(st);
            if(ans!=0)break;
            moves++;
        }
        cout<<ans<<endl;
        if(ans!=0){
            vector<string> temp;
            temp.push_back(endWord);
            help(temp,path,parent,beginWord,endWord,ans-1);
        }
        for(int i=0;i<path.size();i++){
            reverse(path[i].begin(),path[i].end());
        }
        return path;

    }
};