class Solution {
public:
    int help(string src,string dst,set<string> &s,int moves,map<string,int> &m){
        if(src==dst){
            return moves;
        }
        m[src]=moves;
        int ans=INT_MAX;
        for(int i=0;i<src.length();i++){
            char ch=src[i];
            for(char c='a';c<='z';c++){
                if(ch==c)continue;
                src[i]=c;
                if(s.find(src)!=s.end()){
                    if(m[src]!=0 && m[src]<moves+1){
                        continue;
                    }
                    s.erase(src);
                    ans=min(ans,help(src,dst,s,moves+1,m));
                    s.insert(src);
                }
            }
            src[i]=ch;
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        } 

        if(s.find(endWord)==s.end())return 0;
        if(beginWord.length()!=endWord.length())return 0;

        int ans=INT_MAX;
        queue<string> q; 
        q.push(beginWord);
        int moves=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    ans=moves; 
                    break;   
                }
                for(int i=0;i<curr.length();i++){
                    char temp=curr[i];
                    for(char ch='a';ch<='z';ch++){
                        if(ch==temp)continue;
                        curr[i]=ch;
                        if(s.find(curr)!=s.end()){
                            s.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i]=temp;
                }
            }
            moves++;
        }
        if(ans==INT_MAX)return 0;
        return ans;  
    }
};