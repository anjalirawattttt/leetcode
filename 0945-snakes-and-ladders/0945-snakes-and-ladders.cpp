class Solution {
public:
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();

        //number to index
        unordered_map<int,pair<int,int>> m;
        bool flag=true;
        int temp=1;  
        for(int i=n-1;i>=0;i--){
            if(flag){
                for(int j=0;j<n;j++){
                    m[temp]={i,j};
                    temp++;
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    m[temp]={i,j};
                    temp++;
                }
            }
            flag=!flag;
        }

        int ans=0;
        vector<int> visited(n*n+1,0);
        queue<int> q;
        q.push(1);
        visited[1]=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int currNum=q.front();
                q.pop();
                if(currNum==n*n)return ans;
                for(int moves=1;moves<=6;moves++){
                    int next=currNum+moves;
                    if(next>(n*n))break;//return -1;
                    int x=m[next].first;
                    int y=m[next].second;
                    if(board[x][y]!=-1){
                        next=board[x][y];
                    }
                    if(!visited[next]){
                        q.push(next);
                        visited[next]=1;
                    }
                }
            }
            ans++;
        }
        return -1;

    }
};