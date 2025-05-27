class Solution {
public:
    void check(vector<vector<int>>& rooms,vector<bool> &visited,int &count,int s){
        count++;
        visited[s]=true;
        if(count==rooms.size())return;
        for(int &v:rooms[s]){
            if(visited[v]==false){
                check(rooms,visited,count,v);   
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int count=0;
        vector<bool> visited(n,false);
        check(rooms,visited,count,0);
        if(count==n)return true;
        return false;   
    }
};