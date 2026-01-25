class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            // cout<<flights[i][0]<<" "<<flights[i][1]<<" "<<flights[i][2]<<endl;
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
        //     }
        // }

        vector<int> dist(n,INT_MAX);
        queue< pair<int,int> > q;
        dist[src]=0;
        q.push({0,src});
        int moves=0;
        bool found=false;

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int d=q.front().first;
                int u=q.front().second;
                q.pop();
                if(u==dst && moves<=k+1){
                    found=true;
                }
                if(moves>k+1)break;
                for( pair<int,int> &p : adj[u] ){
                    int v=p.first;
                    int cost=p.second;
                    // cout<<v<<" "<<cost<<endl;
                    if(dist[v]>d+cost && moves<k+1){
                        dist[v]=d+cost;
                        q.push({dist[v],v});
                    }
                }
            }
            moves++;
            if(moves>k+1)break;
        }
        if(found)return dist[dst];
        return -1;
    }
};