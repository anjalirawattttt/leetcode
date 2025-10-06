class Solution {
public:
    void dfs(int i,vector<bool> &visited,vector<vector<pair<int,int>>> &adj,int &count){
        visited[i]=true;
        for(auto &p:adj[i]){
            if(!visited[p.first]){
                count+=p.second;
                dfs(p.first,visited,adj,count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &connection:connections){
            adj[connection[0]].push_back({connection[1],1});
            adj[connection[1]].push_back({connection[0],0});
        }  
        vector<bool> visited(n,false);
        int count=0;
        dfs(0,visited,adj,count);
        return count;
    }
};