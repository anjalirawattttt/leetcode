class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> rows={0,0,1,1,-1,-1,1,-1};
        vector<int> cols={1,-1,0,-1,1,0,1,-1};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((board[i][j]&1)==1){
                    int lives=0;
                    for(int k=0;k<8;k++){
                        int r = i + rows[k];
                        int c = j + cols[k];
                        if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && (board[r][c]&1)==1)lives++;
                    }
                    if(lives==2 || lives==3){
                        int x=1<<1;
                        board[i][j]=board[i][j]|x;
                    }    
                }
                else{
                    int lives=0;
                    for(int k=0;k<8;k++){
                        int r = i + rows[k];
                        int c = j + cols[k];
                        if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && (board[r][c]&1)==1)lives++;
                    }
                    if(lives==3){
                        int x=1<<1;
                        board[i][j]=board[i][j]|x;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]=board[i][j]>>1;
            }
        }
        

    }
};