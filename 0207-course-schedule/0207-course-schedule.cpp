class Solution {
public:
    bool dfs(vector<bool> &visited,int i,vector<int> &recStack,vector<vector<int>> &adj){
        visited[i]=true;
        recStack[i]=true;
        for(int &u:adj[i]){
            if(visited[u]==false){
                if(!dfs(visited,u,recStack,adj))return false;
            }
            
            else if(recStack[u]==true)return false;
        }
        recStack[i]=false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses,false);
        vector<int> recStack(numCourses,false);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }  

        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                if(!dfs(visited,i,recStack,adj)) return false;;
            }
        } 
        return true;
    }
};