struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put (char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
    }
};
class Trie{
    public:
    Node* root; 
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    // bool search(string &word){
    //     Node* node=root;
    //     for(int i=0;i<word.length();i++){
    //         if(!node->containsKey(word[i]))return false;
    //         node=node->get(word[i]);
    //     }
    //     return node->isEnd();
    // }

    // void dfs(int i,int j,vector<vector<char>> &board,Node* node,string &temp,vector<string> &ans){
    //     Node* next=node->get(board[i][j]);

    //     char old=board[i][j];
    //     temp+=board[i][j];


    //     if(next->isEnd()){
    //         ans.push_back(temp);
    //         next->flag=false;
    //     }
        
    //     board[i][j]='$';

    //     for(int k=0;k<4;k++){
    //         int r=i+rows[k];
    //         int c=j+cols[k];
    //         if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]!='$'){
    //             if(next->containsKey(board[r][c])){
    //                 dfs(r,c,board,next,temp,ans);
    //             }
    //         }
    //     }
    //     temp.pop_back();
    //     board[i][j]=old;
    // }

    // vector<string> findAllWordPresent(vector<vector<char>> &board){
    //     vector<string> ans;
    //     for(int i=0;i<board.size();i++){
    //         for(int j=0;j<board[0].size();j++){
    //             if(root->containsKey(board[i][j])){
    //                 string temp="";
    //                 dfs(i,j,board,root,temp,ans);
    //             }    
    //         }
    //     }
    //     return ans; 
    // }
};
class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    void dfs(int i,int j,vector<vector<char>> &board,Node* node,string &path,vector<string> &ans){
        char c=board[i][j];
        Node* next=node->get(c);
        path.push_back(c);


        if(next->isEnd()){
            ans.push_back(path);
            next->flag=false;
        }
        
        board[i][j]='$';

        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]!='$'){
                if(next->containsKey(board[r][c])){
                    dfs(r,c,board,next,path,ans);
                }
            }
        }
        path.pop_back();
        board[i][j]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(string &word:words){
            t.insert(word);
        } 
        string path="";
        vector<string> ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(t.root->containsKey(board[i][j])){
                    dfs(i,j,board,t.root,path,ans);
                }    
            }
        }
        return ans;
              
    }
};