class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j]='S';
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<board.size() && c<board[0].size() && board[r][c]=='O')dfs(r,c,board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            //first col
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            //last col
            if(board[i][n-1]=='O'){
                dfs(i,n-1,board);
            }
        }

        for(int j=0;j<n;j++){
            //first row
            if(board[0][j]=='O'){
                dfs(0,j,board);
            }
            //last row
            if(board[m-1][j]=='O'){
                dfs(m-1,j,board);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='S')board[i][j]='O';
            }
        }


    }
};