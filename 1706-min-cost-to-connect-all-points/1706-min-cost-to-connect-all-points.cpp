class Solution {
public:
    int findParent(int node,vector<int>& parent){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionBySize(int u,int v,vector<int>& parent,vector<int>& size){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(size[u]>size[v]){
            size[u]+=size[v];
            parent[v]=u;
        }
        else if(size[u]<size[v]){
            size[v]+=size[u];
            parent[u]=v;
        }
        else{
            size[v]+=size[u];
            parent[u]=v;    
        }
    }
    
    static bool myCmp(tuple<int,int,int> a,tuple<int,int,int> b){
        return get<0>(a) < get<0>(b);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        vector<tuple<int,int,int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        } 
        sort(edges.begin(),edges.end(),myCmp);

        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;i++)parent[i]=i;

        int edge=0;
        int weight=0;

        for(auto &e:edges){
            int w=get<0>(e);
            int u=get<1>(e);
            int v=get<2>(e);
            int pu=findParent(u,parent);
            int pv=findParent(v,parent);
            if(pu!=pv){
                weight+=w;
                edge++;
                unionBySize(u,v,parent,size);
            }
            if(edge==n-1)break;
        }

        

        return weight;


    }
};