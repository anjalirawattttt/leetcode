class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        for( auto &edge : edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }  

        vector<int> ans;
        if(n==1)return {0};

        int remaining=n;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        while(!q.empty() && remaining>2){
            int size=q.size();
            remaining-=size;
            while(size--){
                int u = q.front();
                q.pop();
                for(auto &v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==1){
                        q.push(v);
                    }
                }
            }
        }


        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};