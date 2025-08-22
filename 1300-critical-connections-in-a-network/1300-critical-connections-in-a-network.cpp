class Solution {
public:
    void dfs(int u,int parent,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,int &timer,vector<vector<int>> &bridges){
        disc[u]=low[u]=timer++;
        for(int &v:adj[u]){
            if(v==parent)continue;
            if(disc[v]==-1){
                dfs(v,u,adj,disc,low,timer,bridges);
                low[u]=min(low[u],low[v]);

                if(low[v]>disc[u]){
                    bridges.push_back({u,v});
                }
            }
            else{
                low[u]=min(low[u],disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<vector<int>> adj(n);
        for( auto &c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        int timer=0;

        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i,-1,adj,disc,low,timer,bridges);
            }
        }
        return bridges;
    }
};