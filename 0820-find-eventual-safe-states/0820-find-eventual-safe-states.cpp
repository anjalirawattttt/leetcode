class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe;
        int V=graph.size();
        vector<vector<int>> adj(V);
        vector<int> inDegrees(V,0);

        for(int i=0;i<V;i++){
            for(int &v:graph[i]){
                adj[v].push_back(i);
                inDegrees[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegrees[i]==0)q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            safe.push_back(u);
            for(int &v:adj[u]){
                if(--inDegrees[v]==0)q.push(v);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;    
    }
};