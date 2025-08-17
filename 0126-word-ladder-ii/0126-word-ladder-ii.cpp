class Solution {
public:
    void bT(string word,string &beginWord,vector<string> path,vector<vector<string>> &res,unordered_map<string,vector<string>> &parents){
        if(word==beginWord){
            res.push_back(path);
            return;
        }
        for(auto &p:parents[word]){
            path.push_back(p);
            bT(p,beginWord,path,res,parents);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;

        unordered_set<string> s;
        for(string &word:wordList){
            s.insert(word);
        } 
        if(s.find(endWord)==s.end())return res;

        //parents backtracking
        unordered_map<string,vector<string>> parents;
        unordered_set<string> curr,next;
        curr.insert(beginWord);
        bool found=false;
        while(!curr.empty() && !found){
            for(auto &w:curr)s.erase(w);//mark visited

            for(auto &w:curr){
                for(int i=0;i<w.length();i++){
                    string temp=w;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(s.find(temp)!=s.end()){
                            next.insert(temp);
                            parents[temp].push_back(w);
                            if(temp==endWord)found=true;
                        }
                    }
                }
            }
            swap(curr,next);
            next.clear();
        } 


        vector<string> path={endWord};
        bT(endWord,beginWord,path,res,parents);
        for(auto &p:res)reverse(p.begin(),p.end());
        return res;  
    }
};