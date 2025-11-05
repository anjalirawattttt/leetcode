class Solution {
public:
    void bfs(int i,vector< vector < pair<int,int> > >& adj,int &count,vector<bool> &visited){
        for(pair<int,int> &p:adj[i]){
            if(!visited[p.first]){
                visited[p.first]=true;
                if(p.second>0)count++;
                bfs(p.first,adj,count,visited);
            }
            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // vector<bool> visited(n,false);
        vector< vector < pair<int,int> > > adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],-1});
        } 
        vector<bool> visited(n,false); 
        int count=0;
        visited[0]=true;
        bfs(0,adj,count,visited); 
        return count;
    }
};