class Solution {
public:
    

    bool helper(vector<vector<char>>& board, string word,int i,int sr,int sc){
        if(i==word.length())return true;
        if(sr<0 || sc<0 || sr==board.size() || sc==board[0].size() || board[sr][sc]!=word[i] || board[sr][sc]=='#')return false;
        char ch=board[sr][sc];
        board[sr][sc]='#';
        bool op1=helper(board,word,i+1,sr+1,sc);
        bool op2=helper(board,word,i+1,sr-1,sc);
        bool op3=helper(board,word,i+1,sr,sc+1);
        bool op4=helper(board,word,i+1,sr,sc-1);
        board[sr][sc]=ch;
        return op1|op2|op3|op4;

        
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    
                    if(helper(board,word,0,i,j))return true;
                }
            }
        }
        return false;
    }
};