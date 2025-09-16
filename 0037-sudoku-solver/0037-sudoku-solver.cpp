class Solution {
public:
    bool isSafe(int r,int c,int x,vector<vector<char>>& board){
        unordered_set<int> rows;
        unordered_set<int> cols;
        unordered_set<int> grid;
        for(int i=0;i<board.size();i++){
            if(board[i][c]!='.' && board[i][c]-'0'==x)return false;
        }

        for(int j=0;j<board[0].size();j++){
            if(board[r][j]!='.' && board[r][j]-'0'==x)return false;
        }
        int gs,ge;
        if(r<3)gs=0;
        else if(r<6)gs=3;
        else if(r<9)gs=6;
        if(c<3)ge=0;
        else if(c<6)ge=3;
        else if(c<9)ge=6;
        for(int i=gs;i<gs+3;i++){
            for(int j=ge;j<ge+3;j++){
                if(board[i][j]!='.' && board[i][j]-'0'==x)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                //empty
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isSafe(i,j,k,board)){
                            board[i][j]=k+'0';
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }  
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
};