class Solution {
public:
    bool help(int i,vector<int> &color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(i);  
        color[0]=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:graph[u]){
                if(color[v]==-1){
                    color[v]= color[u]==0?1:0;
                    q.push(v);
                }
                else if(color[v]==color[u])return false;
            }
        }  
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!help(i,color,graph))return false;
            }
        }

        return true;
    }
};