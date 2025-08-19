class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            inDegrees[p[0]]++;
        }     

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegrees[i]==0)q.push(i);
        }
        int v=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            v++;
            for(int &v:adj[u]){
                if(--inDegrees[v]==0)q.push(v);
            }
        }

        return v==numCourses?true:false;
    }
};