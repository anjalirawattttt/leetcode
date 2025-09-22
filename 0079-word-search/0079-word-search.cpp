class Solution {
public:
    bool help(int i,int j,int idx,vector<vector<char>>& board, string word){
        if(idx>=word.length())return true;

        char ch=board[i][j];
        board[i][j]='#';
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]==word[idx]){
                if(help(r,c,idx+1,board,word))return true;
            }
        }
        board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(help(i,j,1,board,word))return true;
                }
            }
        }
        return false;
    }
};