class Solution {
public:
    vector<vector<int>> buildAdj(vector<vector<int>>& edges,int n){
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);   
            adj[edges[i][1]].push_back(edges[i][0]); 
        }
        return adj;
    }

    bool findPath(vector<vector<int>> &adj,vector<bool> &visited,int src,int des){
        if(src==des)return true;
        visited[src]=true;
        for(int &v:adj[src]){
            if(visited[v]==false && findPath(adj,visited,v,des)){
                return true;    
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj=buildAdj(edges,n); 
        vector<bool> visited(n,false);
        return findPath(adj,visited,source,destination);

    }
};