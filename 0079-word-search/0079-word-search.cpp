class Solution {
public:
    bool help(vector<vector<char>>& board, string word,int i,int j,int idx){
        if(idx==word.length())return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[idx] || board[i][j]=='#')return false;
        char ch=board[i][j];
        board[i][j]='#';
        bool op1=help(board,word,i+1,j,idx+1);
        bool op2=help(board,word,i-1,j,idx+1);
        bool op3=help(board,word,i,j+1,idx+1);
        bool op4=help(board,word,i,j-1,idx+1);
        board[i][j]=ch;
        return op1|op2|op3|op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(help(board,word,i,j,0))return true;
                }
            }
        }
        return false;
    }
};