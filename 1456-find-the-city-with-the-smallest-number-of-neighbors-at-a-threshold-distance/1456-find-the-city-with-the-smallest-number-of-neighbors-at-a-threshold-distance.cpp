class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        int ans=-1;
        int minn=INT_MAX;

        for(int i=0;i<n;i++){
            vector<int> dist(n,INT_MAX);
            using T=pair<int,int>;
            priority_queue<T,vector<T>,greater<T>> q;
            dist[i]=0;
            q.push({0,i});  

            while(!q.empty()){
                auto [d,u]=q.top();
                q.pop();
                if(d>dist[u])continue;
                for(auto &[v,w]:adj[u]){
                    if(d+w<dist[v]){
                        dist[v]=d+w;
                        q.push({dist[v],v});
                    }
                }
            }  
            int count=0;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(dist[j]<=distanceThreshold)count++;
            }
            if(count<=minn){
                minn=count;
                ans=i;
            }
        }
        return ans;
        
        return -1;
        
    }
};