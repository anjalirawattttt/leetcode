class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {   
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time:times){
            adj[time[0]].push_back({time[1],time[2]});
        } 

        vector<int> dist(n+1,INT_MAX);
        //shortest distance from a node to all other nodes
        queue<pair<int,int>> q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            auto [d,u]=q.front();
            q.pop();
            if(d>dist[u])continue;
            for(auto &[v,time]:adj[u]){
                if(dist[u]+time<dist[v]){
                    dist[v]=dist[u]+time;
                    q.push({dist[v],v});
                }
            }
        }
            

        int time=0;
        for(int i=1;i<=n;i++){
            time=max(time,dist[i]);
        }

        return time==INT_MAX?-1:time;

    }
};