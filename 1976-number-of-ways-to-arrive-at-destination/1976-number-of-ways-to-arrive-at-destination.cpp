class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }   

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        priority_queue<pair<long long,int> , vector<pair<long long,int>> ,greater<pair<long long,int>> > q;
        q.push({dist[0],0}); 

        while(!q.empty()){
            long long d=q.top().first;
            int u=q.top().second;
            q.pop();
            if(d>dist[u])continue;
            for(auto &[v,cost]:adj[u]){
                if(dist[v]>d+cost){
                    ways[v]=ways[u];
                    dist[v]=d+cost;
                    q.push({dist[v],v});
                }
                else if(dist[v]==d+cost){
                    ways[v]=(ways[v]+ways[u])%MOD;
                }
            }
        }

        return (int)ways[n-1];
    }
};