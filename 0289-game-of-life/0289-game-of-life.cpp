class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<int> rows={1,1,1,-1,-1,-1,0,0};
        vector<int> cols={0,1,-1,0,1,-1,1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int currBit=board[i][j]&1;
                if(currBit==0){
                    int liveNeighbors=0;
                    for(int k=0;k<8;k++){
                        int r=i+rows[k];
                        int c=j+cols[k];
                        if(r>=0 && r<m && c>=0 && c<n && (board[r][c]&1)==1)liveNeighbors++;
                        if(liveNeighbors>3)break;
                    }
                    if(liveNeighbors==3)board[i][j]=2;
                }
                else{
                    int liveNeighbors=0;
                    for(int k=0;k<8;k++){
                        int r=i+rows[k];
                        int c=j+cols[k];
                        if(r>=0 && r<m && c>=0 && c<n && (board[r][c]&1)==1)liveNeighbors++;
                        if(liveNeighbors>3)break;
                    }
                    if(liveNeighbors<2 || liveNeighbors>3)board[i][j]=1;
                    else board[i][j]=3;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=board[i][j]>>1;
            }
        }    
    }
};