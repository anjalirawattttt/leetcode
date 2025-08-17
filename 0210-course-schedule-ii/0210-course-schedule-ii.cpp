class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topSort;
        vector<int> inDegrees(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto &edge:prerequisites){
            inDegrees[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegrees[i]==0)q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            topSort.push_back(u);
            for(int &v:adj[u]){
                inDegrees[v]--;
                if(inDegrees[v]==0)q.push(v);
            }
        }
        if(topSort.size()!=numCourses )return {};
        return topSort;   
    }
};