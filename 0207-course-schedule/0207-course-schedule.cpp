class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0); 
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }   
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0)q.push(v);
            }
        }

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]!=0)return false;
        }
        return true;
    }
};