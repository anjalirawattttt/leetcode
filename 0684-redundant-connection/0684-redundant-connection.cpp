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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int> rank(n+1,-1);

        for(auto &edge:edges){
            int u=edge[0];
            int v= edge[1];
            int pu=findParent(u,parent);
            int pv=findParent(v,parent);
            if(pu==pv)return {u,v};
            else{
                doUnion(u,v,parent,rank);
            }
        }

        return {-1,-1};    
    }
};