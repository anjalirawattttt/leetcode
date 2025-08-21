class Solution {
public:
    int findParent(int node,vector<int>&parent){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionBySize(int u,int v,vector<int>& parent,vector<int>& size){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u==v)return;
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

    int removeStones(vector<vector<int>>& stones) {
        int totalStones=stones.size();
        int maxrows=0;
        int maxcols=0;
        for(auto &s:stones){
            maxrows=max(maxrows,s[0]);
            maxcols=max(maxcols,s[1]);
        }
        
        int n=maxrows+1+maxcols+1;
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;i++)parent[i]=i;

        for(auto &s:stones){
            int r=s[0];
            int c=s[1]+maxrows+1;
            int pr=findParent(r,parent);
            int pc=findParent(c,parent);
            if(pr==pc)continue;
            unionBySize(r,c,parent,size);
        }

        int cc=0;
        unordered_set<int> parents;

        for(int i=0;i<n;i++){
            int p=findParent(i,parent);
            if(p==i)continue;
            if(parents.find(p)==parents.end()){
                cc++;
                parents.insert(p);
            }
        }

        return totalStones - cc;

    }
};