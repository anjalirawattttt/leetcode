class Solution {
public:
    void bfs(int u,vector<vector<int>>& isConnected,vector<bool>& visited){
        visited[u]=true;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i]==1 && !visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int V=isConnected.size();
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(i,isConnected,visited);
                ans++;
            }
        }
        return ans;    
    }
};