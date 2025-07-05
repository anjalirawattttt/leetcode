class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row check
        for(int i=0;i<9;i++){
            vector<int> rows(9,0);    
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(rows[board[i][j]-'0'-1]==1)return false;
                    rows[board[i][j]-'0'-1]=1;
                }
            }
        }
        //column check
        for(int j=0;j<9;j++){
            vector<int> cols(9,0);    
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    if(cols[board[i][j]-'0'-1]==1)return false;
                    cols[board[i][j]-'0'-1]=1;
                }
            }
        }
        //grid check
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> grid(9,0);
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        if(board[r+i][c+j]!='.'){
                            if(grid[board[r+i][c+j]-'0'-1]==1)return false;
                            grid[board[r+i][c+j]-'0'-1]=1;
                        }
                    }
                }
            }
        }

        return true;
    }
};