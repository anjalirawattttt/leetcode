class Solution {
public:
    void help(vector<vector<int>>& isConnected , vector<bool>& visited,int i){
        int n=isConnected.size();
        visited[i]=true;
        for(int j=0;j<n;j++){
            if(visited[j]==false && isConnected[i][j]==1){
                help(isConnected,visited,j);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                help(isConnected,visited,i);
                ans++;
            }
        }

         
        return ans;  
    }
};