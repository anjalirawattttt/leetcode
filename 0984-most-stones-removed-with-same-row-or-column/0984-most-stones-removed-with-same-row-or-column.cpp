class Solution {
public:
    void dfs(int i,vector<vector<int>>& stones,vector<bool> &visited){
        visited[i]=true;
        for(int j=0;j<stones.size();j++){
            if(!visited[j]){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dfs(j,stones,visited);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int totalStones=stones.size();
        int cc=0;//connected components

        vector<bool> visited(totalStones,false);

        for(int i=0;i<totalStones;i++){
            if(!visited[i]){                
                dfs(i,stones,visited);
                cc++;
            }
        }


        return totalStones-cc;    
    }
};