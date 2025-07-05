class Solution {
public:
    bool isSafe(int r,int c,int m,int n){
        return r<m && c<n && r>=0 && c>=0;
    }

    bool helper(vector<vector<char>>& board, string word,int i,int sr,int sc){
        if(i==word.length())return true;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r = sr + rows[k];
            int c = sc + cols[k];
            if(isSafe(r,c,board.size(),board[0].size()) && board[r][c]!='#' && board[r][c]==word[i]){
                char ch=board[r][c];
                board[r][c]='#';
                if(helper(board,word,i+1,r,c))return true;
                board[r][c]=ch;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    char ch=board[i][j];
                    board[i][j]='#';
                    if(helper(board,word,1,i,j))return true;
                    board[i][j]=ch;
                }
            }
        }
        return false;
    }
};