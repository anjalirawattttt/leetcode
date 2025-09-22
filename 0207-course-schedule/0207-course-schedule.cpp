class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        //build adj
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        } 
        //build inDegrees
        vector<int> inDegrees(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int& v:adj[i])  {
                inDegrees[v]++;
            } 
        }  
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegrees[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                inDegrees[v]--;
                if(inDegrees[v]==0)q.push(v);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inDegrees[i]!=0)return false;
        }
        return true;

    }
};