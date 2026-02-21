class Solution {
public:
    unordered_map<string,multiset<string>> graph;
    vector<string> res;
    void dfs(string str){
        while(!graph[str].empty()){
            string next=*graph[str].begin();
            graph[str].erase(graph[str].begin());
            dfs(next);
        }
        res.push_back(str);//postorder dfs        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket:tickets){
            graph[ticket[0]].insert(ticket[1]);
        }  

        dfs("JFK");

        reverse(res.begin(),res.end());
        return res;       
    }
};