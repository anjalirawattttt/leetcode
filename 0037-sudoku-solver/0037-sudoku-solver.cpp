class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char k){
        for(int i=0;i<9;i++){
            if(board[row][i]==k)return false;
            if(board[i][col]==k)return false;
            int r = 3*(row/3) + i/3;
            int c = 3*(col/3) + i%3;
            if(board[r][c]==k)return false;
        }
        // int ro = 3*(row/3);
        // int co = 3*(col/3);
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //        if(board[i+ro][j+co]==k)return false; 
        //     }
        // }
        return true;
    }



    bool solve(vector<vector<char>>& board){

        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(board[row][col]=='.'){
                    for(int k='1';k<='9';k++){
                        if(isSafe(board,row,col,k)){
                            board[row][col]=k;
                            if(solve(board))return true;
                            board[row][col]='.';
                        }

                    }
                    //no digit found
                    return false;
                }
            }
        }
        //all cells filled
        return true;
        
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);   

    }
};