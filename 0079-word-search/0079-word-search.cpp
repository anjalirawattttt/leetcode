class Solution {
public:
    vector<int> rows={1,-1,0,0};
    vector<int> cols={0,0,1,-1};
    bool bfs(int i,int j,vector<vector<char>>& board,int idx,string word){
        if(idx==word.length()-1)return true;
        char ch=board[i][j];
        board[i][j]='#';
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && r<board.size() && c>=0 && c<board[0].size() && board[r][c]!='#' && board[r][c]==word[idx+1]){
                if(bfs(r,c,board,idx+1,word)){
                    board[i][j]=ch;
                    return true;
                }
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
                    if(bfs(i,j,board,0,word))return true;
                }
            }
        } 
        return false;   
    }
};