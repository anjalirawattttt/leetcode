class Solution {
public:
    int findParent(int u,vector<int> &parent){
        if(parent[u]==u)return u;
        return parent[u]=findParent(parent[u],parent);
    }
    void doUnion(int u,int v,vector<int> &parent,vector<int> &rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u!=v){
            if(rank[u]>rank[v]){
                rank[u]+=rank[v];
                parent[v]=u;
            }
            else{
                rank[v]+=rank[u];
                parent[u]=v;
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }

        vector<int> parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        vector<int> rank(n,1);
        sort(edges.begin(),edges.end()); 
        int ans=0;
        for(auto &edge:edges){
            int dist=edge[0];
            int i=edge[1];
            int j=edge[2];
            int pi=findParent(i,parent);
            int pj=findParent(j,parent);
            if(pi!=pj){
                doUnion(i,j,parent,rank);
                ans+=dist;
            }
        }  
        return ans;  
    }
};