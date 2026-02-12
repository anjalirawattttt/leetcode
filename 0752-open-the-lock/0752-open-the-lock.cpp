class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string s="0000";
        if(s==target)return 0;

        set<string> st(deadends.begin(),deadends.end());
        if(st.find(s)!=st.end())return -1;
        set<string> visited;

        queue<string> q;
        q.push(s);   
        visited.insert(s);
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                if(curr==target)return moves;
                for(int i=0;i<4;i++){
                    char c=curr[i];
                    if(c>='0' && c<='8'){
                        curr[i]=c+1;
                        if(st.find(curr)==st.end() && visited.find(curr)==visited.end()){
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    else{
                        curr[i]='0';
                        if(st.find(curr)==st.end() && visited.find(curr)==visited.end()){
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }

                    if(c>='1' && c<='9'){
                        curr[i]=c-1;
                        if(st.find(curr)==st.end() && visited.find(curr)==visited.end()){
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    else{
                        curr[i]='9';
                        if(st.find(curr)==st.end() && visited.find(curr)==visited.end()){
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i]=c;
                }
            }
            moves++;
        } 
        return -1;
    }
};