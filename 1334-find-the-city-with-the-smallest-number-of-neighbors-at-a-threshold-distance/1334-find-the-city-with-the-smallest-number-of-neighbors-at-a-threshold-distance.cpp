class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        vector<vector<int>> dist(n,vector<int>(n,1e4+10));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }    

        //floyd warshall algorithm
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int minReachable=INT_MAX;
        int ans=-1;

        for(int i=0;i<n;i++){
            int reachable=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(dist[i][j]<=distanceThreshold){
                    reachable++;
                }
            }
            // cout<<reachable<<endl;
            if(reachable<=minReachable){
                minReachable=reachable;
                ans=i;
            }
        }
        return ans;
    }
};