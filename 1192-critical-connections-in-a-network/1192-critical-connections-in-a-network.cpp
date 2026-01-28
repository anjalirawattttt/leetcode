class Solution {
public:
    void dfs(int p,int u,vector<vector<int>> &adj,vector<int> &disc ,vector<int> &low,int time,vector<vector<int>> &ans){
        disc[u]=time;
        low[u]=time;

        for(int &v:adj[u]){
            if(disc[v]==-1){
                dfs(u,v,adj,disc,low,time+1,ans);
                for(int &a:adj[v]){
                    if(a==u)continue;
                    low[v]=min(low[a],low[v]);
                }

                if(low[v]>disc[u]){
                    ans.push_back({u,v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;

        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> disc(n,-1);
        vector<int> low(n,INT_MAX);

        dfs(-1,0,adj,disc,low,1,ans);
        return ans;    
    }
};